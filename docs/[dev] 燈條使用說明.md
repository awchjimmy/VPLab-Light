
- Examples

```cpp
#include <FastLED.h>
#define NUM_LEDS 40

CRGBArray<NUM_LEDS> leds;
class VPEffectStatic {
  public:
    VPEffectStatic() {
      cur = prev = 0;
      interval = 500; 
    }
  
    void update() {
      cur = millis();
      if (cur - prev > interval) {
        prev = cur;
        leds(rangeStart, rangeEnd) = color;
      }
    }

    void setRange(int rangeStart, int rangeEnd) {
      this->rangeStart = rangeStart;
      this->rangeEnd = rangeEnd;
    }

    void setColor(CRGB color) {
      this->color = color;
    }


  private:
    long cur, prev, interval;
    int rangeStart, rangeEnd;
    CRGB color;
};


VPEffectStatic ledEnvironment;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 8>(leds, NUM_LEDS);

  leds = CRGB::Blue;
  FastLED.show();

  ledEnvironment.setRange(20, 30);
  ledEnvironment.setColor(CRGB::Green);


}

void loop() {
  // put your main code here, to run repeatedly:
  ledEnvironment.update();
  FastLED.show();
}
```
