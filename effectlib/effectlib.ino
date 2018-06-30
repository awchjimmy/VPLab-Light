#include <FastLED.h>
#include "VPEffectStatic.cpp"
#include "VPEffectColorWipe.cpp"
#include "VPEffectBreath.cpp"
#define NUM_LEDS 40

CRGBArray<NUM_LEDS> leds;


VPEffectStatic ledEnvironment;
VPEffectColorWipe ledCoin;
VPEffectBreath ledBreath;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 8>(leds, NUM_LEDS);

  leds = CHSV(128, 255, 100);
  FastLED.show();

  // 屬性設定
  ledEnvironment.setRef(leds);
  ledEnvironment.setRange(30, 40);
  ledEnvironment.setColor(CRGB::Red);
  
  ledCoin.setRef(leds);
  ledCoin.setRange(30, 40);
  ledCoin.setColor(CRGB::Green);
  ledCoin.setInterval(200);

  ledBreath.setRef(leds);
  ledBreath.setRange(10, 20);
  ledBreath.setHSVColor(CHSV(150, 100, 255));
  ledBreath.setInterval(75);


  // 流程設定
  ledEnvironment.startAt(1000);
  ledCoin.startAt(2000);
  ledBreath.startAt(3000);
  
  


}

void loop() {
  // put your main code here, to run repeatedly:
  ledEnvironment.update();
  ledCoin.update();
  ledBreath.update();
  FastLED.show();
}
