#include<FastLED.h>

const int total1 = 90;
const int total2 = 165;
const int total3 = 200;

CRGBArray<total1> leds1;
CRGBArray<total2> leds2;
CRGBArray<total3> leds3;

const static byte COLOR_BLUE = 160; // blue
const int d = 100;
static byte brightness = 0;
static byte sinb = 0;

static uint8_t dot1 = 0;
static uint8_t cycle1 = 60 - 2;

static uint8_t dot2 = 0;
const uint8_t cycle2 = total2 - 2;
const uint8_t skipPoint2 = 63;

static uint8_t dot3 = 0;
const uint8_t cycle3 = total3 - 2;
const uint8_t skipPoint3 = 78;


void setup() {
  Serial.begin(115200);

  FastLED.addLeds<NEOPIXEL, 4>(leds1, total1);
  FastLED.addLeds<NEOPIXEL, 5>(leds2, total2);
  FastLED.addLeds<NEOPIXEL, 6>(leds3, total3);

  leds1 = CRGB::Black;
  leds2 = CRGB::Black;
  leds3 = CRGB::Black;

  FastLED.show();
}

void loop() {
  sinb = sin8(brightness);

  // 硬幣
  leds1(60, 89) = CHSV(COLOR_BLUE, 255, sinb);
  leds2(65, 124) = CHSV(COLOR_BLUE, 255, sinb);
  leds3(80, 134) = CHSV(COLOR_BLUE, 255, sinb);

  // 水流燈
  leds1(dot1, dot1 + 2) = CRGB::Blue;
  leds2(dot2, dot2 + 2) = CRGB::Blue;
  leds3(dot3, dot3 + 2) = CRGB::Blue;

  // Serial.println(dot1);
  FastLED.show();

  // update value below //


  brightness += 4;

  leds1(0, total1).fadeToBlackBy(128);
  leds2(0, total2).fadeToBlackBy(128);
  leds3(0, total3).fadeToBlackBy(128);

  dot1 = (dot1 + 1) % cycle1;
  dot2 = (dot2 + 1) % cycle2;
  dot3 = (dot3 + 1) % cycle3;

  if (dot2 == skipPoint2) {
    dot2 += 62;
  }
  if (dot3 == skipPoint3) {
    dot3 += 57;
  }

  delay(47);
}
