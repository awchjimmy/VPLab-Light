#include<FastLED.h>

CRGBArray<120> leds1;
CRGBArray<240> leds2;
CRGBArray<170> leds3;

const static byte COLOR_BLUE = 160; // blue
const int d = 100;
static byte brightness = 0;
static byte sinb = 0;

static uint8_t dot1 = 0;
static uint8_t cycle1 = 58;
const uint8_t off1 = 30;
static uint8_t len1 = 2;

static uint8_t dot2 = 0;
const uint8_t cycle2 = 238;
const uint8_t skipPoint2 = 83;

static uint8_t dot3 = 0;
const uint8_t cycle3 = 168;
const uint8_t skipPoint3 = 68;


void setup() {
  Serial.begin(115200);

  FastLED.addLeds<NEOPIXEL, 4>(leds1, 120);
  FastLED.addLeds<NEOPIXEL, 5>(leds2, 240);
  FastLED.addLeds<NEOPIXEL, 6>(leds3, 170);

  leds1 = CRGB::Black;
  leds2 = CRGB::Black;
  leds3 = CRGB::Black;

  FastLED.show();
}

void loop() {
  // 手機
  // leds1(0, 29) = CRGB::Black;

  sinb = sin8(brightness);

  // 硬幣
  leds1(91, 120) = CHSV(COLOR_BLUE, 255, sinb);
  leds2(85, 144) = CHSV(COLOR_BLUE, 255, sinb);
  leds3(70, 129) = CHSV(COLOR_BLUE, 255, sinb);

  // 水流燈
  leds1(dot1 + off1, dot1 + len1 + off1) = CRGB::Blue;
  leds2(dot2, dot2 + 2) = CRGB::Blue;
  leds3(dot3, dot3 + 2) = CRGB::Blue;

  // Serial.println(dot1);
  FastLED.show();

  // update value below //


  brightness += 4;
  //  leds1(dot1 + off1, dot1 + len1 + off1) = CRGB::Black;
  //  leds2(dot2, dot2 + 2) = CRGB::Black;
  //  leds3(dot3, dot3 + 2) = CRGB::Black;
  //  leds1.fadeToBlackBy(128);
  leds1(30, 90).fadeToBlackBy(128);
  leds2(0, 240).fadeToBlackBy(128);
  leds3(0, 170).fadeToBlackBy(128);

  dot1 = (dot1 + 1) % cycle1;
  dot2 = (dot2 + 1) % cycle2;
  dot3 = (dot3 + 1) % cycle3;
  if (dot2 == skipPoint2) {
    dot2 += 62;
  }
  if (dot3 == skipPoint3) {
    dot3 += 62;
  }

  if (dot1 == 0) {
    len1 = 2;
    cycle1 = 60 - len1;
  }

  delay(47);
}
