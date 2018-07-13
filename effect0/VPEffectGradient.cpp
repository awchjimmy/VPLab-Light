#include <FastLED.h>

struct MRGB {
  float r;
  float g;
  float b;

  MRGB() {
    r = g = b = 0;
  }

  MRGB(CRGB col) {
    r = col.red;
    g = col.green;
    b = col.blue;
  }

  MRGB(int x, int y, int z) {
    r = x;
    g = y;
    b = z;
  }

  CRGB getColor() {
    return CRGB(uint8_t(r), uint8_t(g), uint8_t(b));
  }

  void operator+=(const MRGB& other) {
    this->r += other.r;
    this->g += other.g;
    this->b += other.b;
  }

  void operator-=(const MRGB& other) {
    this->r -= other.r;
    this->g -= other.g;
    this->b -= other.b;
  }

  void operator/=(int d) {
    this->r /= d;
    this->g /= d;
    this->b /= d;
  }
};

MRGB operator+(MRGB a, MRGB b) { a+=b; return a; }
MRGB operator-(MRGB a, MRGB b) { a-=b; return a; }
MRGB operator/(MRGB a, int b) { a/=b; return a; }
    
class VPEffectGradient {
  public:
    VPEffectGradient() {
      cur = prev = millis();
      interval = 50;
      __show = false;
      nextColorIndex = -1;
    }

    void update() {

      cur = millis();

      // startAt(duration);
      if (cur - prev >= duration && __firsttime) {
        __firsttime = false;
        __show = true;
        
        if(nextColorIndex == -1) {
          currColor = generateRandomColor();
          nextColor = generateRandomColor();
          stepColor = (nextColor - currColor) / stepCount;
        }
        else {
          currColor = colorArray[0];
          nextColor = colorArray[1];
          nextColorIndex = 2 % colorArraySize;
          stepColor = (nextColor - currColor) / stepCount;
        }
      }

      if (__show && cur - prev > interval) {
        prev = cur;
        mainEffectLogic();
      }
    }

    void mainEffectLogic() {
      if(stepCount == 0) {
        //update color
        currColor = nextColor;
        if(nextColorIndex == -1) {
          nextColor = generateRandomColor();
        }
        else {
          nextColor = colorArray[nextColorIndex];
          nextColorIndex = (nextColorIndex + 1) % colorArraySize;
        }
        stepColor = (nextColor - currColor) / stepCount;
      }
      else {
        stepCount--;
      }

      currColor += stepColor;
      CRGB updatedColor = currColor.getColor();
      fill_solid(__leds+rangeStart, rangeEnd-rangeStart+1, currColor.getColor());
    }

    void setRef(CRGB* crgbarrayVar) {
      __leds = crgbarrayVar;
    }

    void setRange(int rangeStart, int rangeEnd) {
      this->rangeStart = rangeStart;
      this->rangeEnd = rangeEnd;
    }

    void setColor(CRGB* color, int sz) {
      //sz must >= 2
      colorArray = color;
      colorArraySize = sz;
    }

    void startAt(long duration) {
      __firsttime = true;
      cur = prev = millis();
      this->duration = duration;
    }

    void setInterval(long interval) {
      this->interval = interval;
    }

    void setStepCount(int cnt) {
      if(cnt <= 2) cnt = 2;
      stepCount = cnt;
    }

  private:
    CRGB* __leds;
    CRGB* colorArray;
    long cur, prev, interval;
    long duration;
    bool __firsttime, __show;
    int rangeStart, rangeEnd;
    int stepCount;
    int nextColorIndex, colorArraySize;
    MRGB currColor, nextColor;
    MRGB stepColor;

    CRGB generateRandomColor() {
      return CRGB(random()%256, random()%256, random()%256);
    }
};
