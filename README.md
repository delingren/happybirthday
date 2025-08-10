In this assignment, you will program a Pro Micro to display a message on a LCD screen. The color of the text and background flash every 0.5 seconds. Here is a demo video.

![demo](./demo.mov)

# Hardware

List of parts:

* Pro Micro, an Arduino clone
* 160x80 SPI display, powered by ST7735
* Bread board
* Wires
* USB cable

# Steps

## Arduino programming bacis

* [Install Arduino IDE](https://www.arduino.cc/en/Guide/)
* Here's a [post](https://forum.arduino.cc/t/material-and-courser-outline-for-11-12-year-olds/567386/2) with great resources for Arduino for kids. 

## Breadboard basics

[This](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all) is a great resource.

## Wiring up an SPI display

Refer to this [tutorial](https://learn.adafruit.com/1-8-tft-display/breakout-wiring-and-test) for wiring up the display with the Arduino. Keep in mind that our hardware is slightly different in the following ways:

* Our display's resolution is 160x80

* We are using an Arduino Leonardo clone, not an Arduino Uno. You are going to need these pins:
  - Raw (5V)
  - GND
  - 15 (SCLK)
  - 16 (MOSI)
  - RES, DC, and CS pins can be any other GPIO pins. I used 7, 8, and 9. But you don't need to.

## Learn the libraries

You are going to need two libraries:

* Adafruit GFX Graphics Library. follow this [tutorial](https://learn.adafruit.com/adafruit-gfx-graphics-library/overview) to install. Also read through the rest of the tutorial until Rotating the Display section. The rest is less relevant to this assignment. Pay special attention to Characters and Text.

* Adafruit ST7735 TFT Library, follow this aforementioned [tutorial](https://learn.adafruit.com/1-8-tft-display/breakout-wiring-and-test) to install and learn about the `graphicstest` example. Our display is `INITR_MINI160x80_PLUGIN`.

* You are going to need at least these functions: 
  - `setTextColor`
  - `fillScreen`
  - `setTextSize`
  - `setCursor`
  - `print`

* The library also defines the following colours. I used all of them in the demo video. You can also define your own colours. The display uses 16 bits for colour. The format is 5(R)+6(G)+5(B).  
`ST77XX_RED`, `ST77XX_GREEN`, `ST77XX_BLUE`, `ST77XX_CYAN`, `ST77XX_MAGENTA`, `ST77XX_YELLOW`, `ST77XX_ORANGE`,  `ST77XX_BLACK`, `ST77XX_WHITE`