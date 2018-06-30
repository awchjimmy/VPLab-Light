#include <FastLED.h>

class VPEffectStatic {
  public:
    VPEffectStatic() {
      cur = prev = millis();
      interval = 50;
      __show = false;
    }

    void update() {


      cur = millis();

      // startAt(duration);
      if (cur - prev < duration) {
      } else if (__firsttime) {
        __firsttime = false;
        __show = true;
      } else {
        // already start, nothing to do here.
      }


      if (__show && cur - prev > interval) {
        prev = cur;

        for (int i = rangeStart; i < rangeEnd; i++) {
          __leds[i] = color;
        }

        __show = false;
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

    void startAt(long duration) {
      __firsttime = true;
      cur = prev = millis();
      this->duration = duration;
    }



  private:
    CRGB* __leds;
    long cur, prev, interval;
    long duration;
    bool __firsttime, __show;
    int rangeStart, rangeEnd;
    CRGB color;
};
