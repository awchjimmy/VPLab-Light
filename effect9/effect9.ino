#include<FastLED.h>
#define NUM_LEDS 360

CRGBArray<NUM_LEDS> leds;
int INTERVAL = 75;

const int totalDots = 24;
const int factor = 15;
const uint8_t BLUE = 140;


class Flow {
    int dot = 0;
    int prev = 0;

  public:
    void setDot(int dot) {
      this->dot = dot;
    }
    void doNext() {
      int cur = millis();
      if (cur - prev > INTERVAL) {
        prev = cur;

        leds[dot] = CHSV(BLUE, 100, 255);

        dot--;
        if (dot < 0) dot = NUM_LEDS - 1;
      }
    }
};


Flow f[totalDots];

void setup() {
  FastLED.addLeds<NEOPIXEL, 8>(leds, NUM_LEDS);
  for (int i = 0; i < totalDots; i++) {
    f[i].setDot(i * factor);
  }
}

void loop() {
  for (int i = 0; i < totalDots; i++) {
    f[i].doNext();
  }
  FastLED.show();


  delay(33);
  leds.fadeToBlackBy(16);

}
