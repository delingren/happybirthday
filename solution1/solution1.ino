#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS 9
#define TFT_RST 7
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  tft.initR(INITR_MINI160x80_PLUGIN);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextWrap(false);
}

void loop() {
  uint16_t fgColors[7] = {ST77XX_RED,   ST77XX_GREEN,   ST77XX_BLUE,
                          ST77XX_CYAN,  ST77XX_MAGENTA, ST77XX_YELLOW,
                          ST77XX_ORANGE};
  uint16_t bgColors[9] = {ST77XX_RED,    ST77XX_GREEN,   ST77XX_BLUE,
                          ST77XX_CYAN,   ST77XX_MAGENTA, ST77XX_YELLOW,
                          ST77XX_ORANGE, ST77XX_BLACK,   ST77XX_WHITE};
  static int fg = 0;
  static int bg = 0;

  tft.setTextColor(fgColors[fg]);
  tft.fillScreen(bgColors[bg]);
  printText();
  delay(800);
  fg = (fg + 1) % 7;
  bg = (bg + 2) % 9;
  if (fgColors[fg] == bgColors[bg]) {
    bg = (bg + 1) % 9;
  }
}

void printText() {
  tft.setTextSize(4);
  tft.setCursor(20, 8);
  tft.print("HAPPY");
  tft.setTextSize(3);
  tft.setCursor(8, 48);
  tft.print("BIRTHDAY");
}
