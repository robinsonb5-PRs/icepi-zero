### Journal for the Icepi Zero!

I'll write a bit about my journey here :D

The journey all started when Hackclub's onboard live program was going to end. I've had 100$ worth of grants left, so I thought furiously about what I wanted - and the answer is a FPGA.

I've always wanted a FPGA from when I was 13, but they were just too expensive for me. So I've took the simplest ICE40 and made this, called anice:

![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/721048f0d512cbbb068bd766951713756cae847d_image.png)

Not bad tbh, went through multiple revisions. Got these boards and found out I made a few design errors though:

- I used an crystal instead of an crystal oscillator in the clock footprint
- The flashing half-works, idk how I designed it

Also it has few big flaws:

- It needed an external programmer
- It only has 4k LUTs
- Doesn't have enough built-in I/Os
- Missing a GPDI port!

The missing GPDI port was the biggest problem for me as I wanted to make my own CPU and OS on it :)

https://www.reddit.com/r/PrintedCircuitBoard/comments/1jzs6o1/review_ice40_development_board/

So it was time to rack the intensity up!

I've decided to use the ECP5 on my second prototype, for it's open source toolchain and it's price.

This was my original prototype:

![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/70d659c12deafe876fc1503fcd26827a245099ee_image.png)
![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/3c03c84bba89d85bb84375060f88e98dae796522_image.png)

It was called anice and had a rpi-like factor, like way larger then a rpi. I sent this to review on reddit:

https://www.reddit.com/r/PrintedCircuitBoard/comments/1k7v7yk/review_request_ecp5_development_board/



![Pre-alpha Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/4c0861d350addacafd7bc4966b30fc04cd840f32_image.png)

![V1.0 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/ec8ed16af61150195ea388c32047b6e1b9825b63_image.png)

![V1.1 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/ec8ed16af61150195ea388c32047b6e1b9825b63_image.png)

![Current V1.3 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/14ae8200592e3d37a41da3d91fc7d38234ea2173_image.png)


https://www.reddit.com/r/electronics/comments/1kwwwm0/i_built_the_fpga_raspberry_pi_zero_equivalent/
https://www.reddit.com/r/embedded/comments/1kwx5p7/i_built_the_fpga_raspberry_pi_zero_equivalent/
https://www.reddit.com/r/PrintedCircuitBoard/comments/1kwxf7y/thanks_for_the_reviews_icepi_zero_came_back/
https://www.reddit.com/r/FPGA/comments/1kwxvk8/ive_made_my_first_fpga_board_the_icepi_zero/
https://www.reddit.com/r/raspberry_pi/comments/1kxag0m/i_built_the_fpga_raspberry_pi_zero_equivalent/

https://hackaday.com/2025/05/29/icepi-zero-a-pi-zero-for-fpga/

https://certification.oshwa.org/fr000026.html

26th open source project of France... Wild.

Big thanks to:
- Acon
- Itai
- Hackclub
- Everyone from the KiCAD discord and reddit :)
