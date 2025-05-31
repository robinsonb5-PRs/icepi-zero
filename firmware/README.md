# Icedev Zero Firmware

Welcome to the firmware folder! You can find numerous examples here:

- `blinky`: Classic LED counter!
- `counter`: Counter using the button as input :D
- `uart`: Uart transmission example
- `third-party`: Third party verilog code
    - `memtest`: Memory tester w/ hdmi output! Pressing the button increases skew, middle row displays memory test cout, bottom row displays the number of bad memory reads.

## Toolchain setup

Download the latest build of the [OSS CAD Suite](https://github.com/YosysHQ/oss-cad-suite-build/releases/).

Unzip it anywhere and set shell command search path:
```
Linux              : export PATH=[path-to-bin]:$PATH
MacOS              : export PATH=[path-to-bin]:$PATH
Windows Powershell : $ENV:PATH = "[path-to-bin];" + $ENV:PATH
Windows cmd.exe    : PATH=[path-to-bin];%PATH%
```

## How to build

Just `cd` into the directories, and type `make`!

- `make` runs `make debug`
- `make debug` installs the program to chip (bitstream is lost on power loss)
- `make install` installs the program to flash
- `make install-bitstream` installs the `bitstream.bit` file to flash without rebuilding
- `make build` builds the bitstream (bitstream is retained on power loss)
- `make clean` deletes all the temporary files

## Make your own!

Just copy the `icepi-zero.lpf` and `Makefile` to the root of your directory, call your main module `top`, and you are good to go!

## How to flash

The following command is used to flash the development board

```zsh
openFPGALoader -cft231X --pins=7:3:5:6 bitstream.bit
```

You can also add the `--write-flash` flag to permanantly write the bitstream to flash.

Note: If you use the newest version of openFPGALoader, it supports the `-b icepi-zero` flag that can replace `-cft231X --pins=7:3:5:6`.

## Pinout

To come soon
