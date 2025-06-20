# From nothing to Icepi

## The start

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

## Objective: Icepi Zero

I've decided to use the ECP5 on my second prototype, for it's open source toolchain and it's price.

This was my original prototype:

![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/70d659c12deafe876fc1503fcd26827a245099ee_image.png)
![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/3c03c84bba89d85bb84375060f88e98dae796522_image.png)

It was called anice and had a rpi-like factor, like way larger then a rpi. I sent this to review on reddit:

https://www.reddit.com/r/PrintedCircuitBoard/comments/1k7v7yk/review_request_ecp5_development_board/

Wow, I got so much feedback (and found so many imperfections). Off to v2 I go!

I've compleatly restarted the project - this time found a better uSD slot in order to fit my board on a true rpi footprint, and rerouted everything from zero:

![WIP icepi](https://hc-cdn.hel1.your-objectstorage.com/s/v3/0b80934d9d930c9dbdf825f8e827b0cd9b55f702_image.png)

After a few days of blood and sweat (~And not studying for exams~), this is the final result I got:

![Pre-alpha Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/4c0861d350addacafd7bc4966b30fc04cd840f32_image.png)

Looks awesome! I've also showcased this on the KiCAD Discord:

![500 messages on the Discord thread,,, wow](https://hc-cdn.hel1.your-objectstorage.com/s/v3/4b43bd310df340b040859aec1a4dbd5efdf11f24_image.png)

The people in that community were super helpful, spotted quite a few errors for me: The thread ended up containing ~500 messages :O just wow.

With the help of some people on reddit and Max from our Hackclub slack, I've finished the v1.0 of the Icepi Zero (Check out Max's awesome [Tiny4FSK](https://github.com/New-England-Weather-Balloon-Society/Tiny4FSK)!)

![V1.0 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/ec8ed16af61150195ea388c32047b6e1b9825b63_image.png)

This isn't actually v1.0, I ended up rerouting like 4 times in the process.

![pre-v1.0](https://hc-cdn.hel1.your-objectstorage.com/s/v3/d448ff4445b6dd00e6bb448495681dbc28a95d1c_image.png)

Off to production you go!

![V1.0 order](https://hc-cdn.hel1.your-objectstorage.com/s/v3/160996802b5b9ca3391581e75304b720e4cb1059_image.png)

I've tried to receive some funding to elevate the cost: I've contacted pcbway for sponsoring, they said yes to sponsor the cost of the PCBs, but not the PCBA. Aaand their PCBA was actually more costly then that of jlcpcb.

## Shipping off the project

After verifing that the basic functionallity works, I've started to actually *ship* my project:

https://www.reddit.com/r/electronics/comments/1kwwwm0/i_built_the_fpga_raspberry_pi_zero_equivalent/
https://www.reddit.com/r/embedded/comments/1kwx5p7/i_built_the_fpga_raspberry_pi_zero_equivalent/
https://www.reddit.com/r/PrintedCircuitBoard/comments/1kwxf7y/thanks_for_the_reviews_icepi_zero_came_back/
https://www.reddit.com/r/FPGA/comments/1kwxvk8/ive_made_my_first_fpga_board_the_icepi_zero/
https://www.reddit.com/r/raspberry_pi/comments/1kxag0m/i_built_the_fpga_raspberry_pi_zero_equivalent/

Holy, that blew up. Seems like people were interested in the project :D

After that, I've found out that Hackaday had a tip line, so I sent my project in :) https://hackaday.com/submit-a-tip/ and a few days later, guess what I saw on the front page:

https://hackaday.com/2025/05/29/icepi-zero-a-pi-zero-for-fpga/

OH MY GOD! Being on there was my dream! I was shaking with exitement.

In the few days that followed, one of my friends sent me this picture:

![Hackernews vial](https://hc-cdn.hel1.your-objectstorage.com/s/v3/ffae74210ece3561581ac6f613e279b7f69803f8_image.png)

Oh wow! I went to Hackernews front page too! (Yea IK it's my account, I posted it :P)

I also had to make my certifications compleate, so I've submitted my project to OSHWA, and they gove me an open source hardware certification!

https://certification.oshwa.org/fr000026.html

26th open source project of France... Wild.

![V1.1 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/ec8ed16af61150195ea388c32047b6e1b9825b63_image.png)

![Current V1.3 Icepi Zero](https://hc-cdn.hel1.your-objectstorage.com/s/v3/14ae8200592e3d37a41da3d91fc7d38234ea2173_image.png)

Currently I've ordered a batch of the Icepi Zero v1.3! Really exited ^.^

![](https://hc-cdn.hel1.your-objectstorage.com/s/v3/91e3fe3b7048b2c0372d040cbdc0bf52ea27ed20_image.png)

## Special thanks

Here at the end, I offer my profound thanks to Itai, for starting https://reflow.badbird.dev/, without which I would never have started this enourmous project.

Thanks to everyone who gave me a review on Reddit, for making me realize my flaws.

Thanks to Mpk and all the passionate engineers on the KiCAD Discord, for reviewing my PCB and instructing me on the aspects I lacked - without you the boards would never have worked.

Thanks to Echo, for helping me amass the funds for the first batch of boards. And at last Hackclub, for fostering such a great community of teen engineers.

Also Acon for the cute pfp you drew :D

