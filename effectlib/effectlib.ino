#include <FastLED.h>
#include "VPEffectStatic.cpp"
#define NUM_LEDS 40

CRGBArray<NUM_LEDS> leds;


VPEffectStatic ledEnvironment;
VPEffectStatic ledEnvironment2;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 8>(leds, NUM_LEDS);

  leds = CRGB::Blue;
  FastLED.show();

  // 屬性設定
  ledEnvironment.setRef(leds);
  ledEnvironment.setRange(20, 30);
  ledEnvironment.setColor(CRGB::Red);
  
  ledEnvironment2.setRef(leds);
  ledEnvironment2.setRange(30, 35);
  ledEnvironment2.setColor(CRGB::Green);

  // 流程設定
  ledEnvironment.startAt(3000);
  ledEnvironment2.startAt(5000);


}

void loop() {
  // put your main code here, to run repeatedly:
  ledEnvironment.update();
  ledEnvironment2.update();
  FastLED.show();
}
