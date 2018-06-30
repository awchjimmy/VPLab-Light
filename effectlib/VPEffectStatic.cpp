#include <FastLED.h>

class VPEffectStatic {
  public:
    VPEffectStatic() {
      cur = prev = millis();
      interval = 500;
    }

    void update() {


      cur = millis();

      // startAt(duration);
      // TODO: only start once, fix required
      if (cur - prev < duration) {
        return;
      }




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

    /*
      void start() {
      __stop = false;
      }

      void stop() {
      __stop = true;
      }
    */

    void startAt(long duration) {
      cur = prev = millis();
      this->duration = duration;
    }



  private:
    CRGB* __leds;
    long cur, prev, interval;
    long duration;
    int rangeStart, rangeEnd;
    CRGB color;
};
