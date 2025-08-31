#include <iostream>
#include <string>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <SDL3/SDL.h>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "../obj_dir/Vvga.h"

constexpr int DEFAULT_W = 640;
constexpr int DEFAULT_H = 480;

static auto destroyWindow = [](SDL_Window* w) { SDL_DestroyWindow(w); };
static auto destroyRenderer = [](SDL_Renderer* r) { SDL_DestroyRenderer(r); };
static auto destroyTexture = [](SDL_Texture* r) { SDL_DestroyTexture(r); };

static std::unique_ptr<SDL_Window, decltype(destroyWindow)> window;
static std::unique_ptr<SDL_Renderer, decltype(destroyRenderer)> renderer;
static std::unique_ptr<SDL_Texture, decltype(destroyTexture)> texture;
static std::unique_ptr<std::uint32_t> screen;

static int frames;
static std::uint64_t ticks;

int setupVGA() {
    SDL_SetAppMetadata("VGA simulator", "1.0", "com.cyao.vgasimulator");
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer("VGA verilog simulator", DEFAULT_W, DEFAULT_H, 0,
                                     std::out_ptr(window), std::out_ptr(renderer))) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    texture = decltype(texture)(SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_RGBA8888,
                                        SDL_TEXTUREACCESS_STREAMING, DEFAULT_W, DEFAULT_H));

	SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_NONE);
	SDL_SetTextureBlendMode(texture.get(), SDL_BLENDMODE_NONE);
	SDL_SetWindowPosition(window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_RaiseWindow(window.get());

    screen = decltype(screen)(new std::uint32_t[DEFAULT_W * DEFAULT_H]);

    SDL_memset(screen.get(), 0xFF, DEFAULT_W * DEFAULT_H * 4);

    return 0;
}

int drawVGA(Vvga* vga) {
    static int x;

    static int pitch;
	static void* pixels;

    if (vga->de) {
        screen.get()[x] = (static_cast<std::uint32_t>(vga->vga_b) <<  8) ^
                          (static_cast<std::uint32_t>(vga->vga_g) << 16) ^
                          (static_cast<std::uint32_t>(vga->vga_r) << 24);

        x += 1;
    } else {
        // Let us quit
        SDL_Event e;
        SDL_PollEvent(&e);
        [[unlikely]] if (e.type == SDL_EVENT_QUIT) {
            return 1;
        }

        if (!vga->vsync && x != 0) {
            x = 0;

            SDL_LockTexture(texture.get(), NULL, &pixels, &pitch);

            assert(pitch == sizeof(std::uint32_t) * DEFAULT_W);

            SDL_memcpy(pixels, screen.get(), DEFAULT_W * DEFAULT_H * sizeof(std::uint32_t));
            SDL_UnlockTexture(texture.get());
            SDL_RenderTexture(renderer.get(), texture.get(), NULL, NULL);
            SDL_RenderPresent(renderer.get());

            frames += 1;

            if (SDL_GetTicks() - ticks > 2000) { // Per 2 seconds
                std::cout << "FPS:" << static_cast<float>(frames) / (static_cast<float>(SDL_GetTicks() - ticks) / 1000) << std::endl;
                frames = 0;
                ticks = SDL_GetTicks();
            }
        }

        return 0;
    }

    return 0;
}

int main(int argc, char** argv) {
    // Parse cli options
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help",      "display this text and exit")
        ("trace",     "produce waveform dump")
        ("tracefile", po::value<std::string>()->default_value("wave.vcd"), "waveform file name")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // Print help message
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (setupVGA()) {
        return 1;
    }

    Verilated::mkdir("logs");
    VerilatedVcdC* tfp = nullptr;
    VerilatedContext* const contextp = new VerilatedContext;
    contextp->debug(0); // 0 is off, 9 highest
    
    bool trace = false;
    if (vm.count("trace")) {
        contextp->traceEverOn(true);
        trace = true;
    } else {
        contextp->traceEverOn(false);
    }

    contextp->commandArgs(argc, argv);

    const auto top = std::unique_ptr<Vvga>(new Vvga(contextp, "TOP"));
    // Trace to 99 depth
    if (trace) {
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open(vm["tracefile"].as<std::string>().data());
    }

    ticks = SDL_GetTicks();
    while (!contextp->gotFinish()) {
        contextp->timeInc(1); // Time is passing uwu
        top->clkp = !top->clkp; // 50MHz clock
        
        // Signals are posedge in verilog, so we change on negedge
        if (!top->clkp) {
            // TODO: LED and btn

            if (drawVGA(top.get())) {
                // Quit
                return 0;
            }
        }

        top->eval();

        if (trace) {
            tfp->dump(contextp->time());
        }
    }

    if (trace) {
        tfp->close();
    }
    top->final();
}
