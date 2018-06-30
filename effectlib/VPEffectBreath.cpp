#include <FastLED.h>

class VPEffectBreath {
  public:
    VPEffectBreath() {
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
      for (int i = rangeStart; i < rangeEnd; i++) {
        __leds[i] = CHSV(color.hue, color.sat, sin8(__brightness));
      }

      // update
      __brightness = (__brightness + 4);
      if (sin8(__brightness) < 20) {
        // the last iteration
        __brightness = 0;
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

    void setHSVColor(CHSV color) {
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
    uint8_t __brightness;
    
    CHSV color;
};
