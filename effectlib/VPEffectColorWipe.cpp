#include <FastLED.h>

class VPEffectColorWipe {
  public:
    VPEffectColorWipe() {
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

        mainEffectLogic();
      }
    }

    void mainEffectLogic() {
      // set
      __leds[currentDot] = color;

      // update
      currentDot = (currentDot + 1);
      if (currentDot >= rangeEnd) {
        // the last iteration
        currentDot = rangeStart;
        __show = false;
      }
    }

    void setRef(CRGB* crgbarrayVar) {
      __leds = crgbarrayVar;
    }

    void setRange(int rangeStart, int rangeEnd) {
      this->rangeStart = rangeStart;
      this->rangeEnd = rangeEnd;
      this->currentDot = rangeStart;
    }

    void setColor(CRGB color) {
      this->color = color;
    }

    void startAt(long duration) {
      __firsttime = true;
      cur = prev = millis();
      this->duration = duration;
    }

    void setInterval(long interval) {
      this->interval = interval;
    }



  private:
    CRGB* __leds;
    long cur, prev, interval;
    long duration;
    bool __firsttime, __show;
    int rangeStart, rangeEnd;
    int currentDot;
    CRGB color;
};
