#include <FastLED.h>

#define NUMLEDS1 40

CRGBArray<NUMLEDS1> leds1;

class Coin {
  private:
    CRGB* leds;
    int dotStart;
    int dotEnd;
    uint8_t brightness;
    bool _start;

    long prev;

  public:
    Coin(CRGB* leds, int dotStart, int dotEnd) {
      this->leds = leds;
      this->dotStart = dotStart;
      this->dotEnd = dotEnd;
    }

    void update() {
      long  cur = millis();
      if (_start && cur - prev > 50) {
        prev = cur;


        for (int i = dotStart; i < dotEnd; i++) {
          leds[i] = CHSV(0, 255, sin8(brightness));
        }


        // stop condition
        if (sin8(brightness) == 1) {
          _start = false;
          for (int i = dotStart; i < dotEnd; i++) {
            leds[i] = CRGB::Black;
          }
        }

        // next iteration
        brightness++;
      }
    }

    void start() {
      _start = true;
    }
};

Coin coin(leds1, 0, 3);
Coin coin2(leds1, 20, 25);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 13>(leds1, NUMLEDS1);


  Serial.begin(115200);
  
  coin.start();
}

void loop() {
  // put your main code here, to run repeatedly:

  coin.update();
  coin2.update();

  FastLED.show();

}
