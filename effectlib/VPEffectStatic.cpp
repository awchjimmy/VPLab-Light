#include <FastLED.h>

class VPEffectStatic {
  public:
    VPEffectStatic() {
      cur = prev = millis();
      interval = 50;
    }

    void update() {
      cur = millis();
      if (cur - prev > interval) {
        prev = cur;
        //leds(rangeStart, rangeEnd) = color;
        for (int i = rangeStart; i < rangeEnd; i++) {
          __leds[i] = color;
        }
      }
    }

    void setRef(CRGB* crgbarrayVar) {
      __leds = crgbarrayVar;
    }

    void setRange(int rangeStart, int rangeEnd) {
      this->rangeStart = rangeStart;
      this->rangeEnd = rangeEnd;
    }

    void setColor(CRGB color) {
      this->color = color;
    }

    void start() {
    }



  private:
    CRGB* __leds;
    long cur, prev, interval;
    int rangeStart, rangeEnd;
    CRGB color;
};
