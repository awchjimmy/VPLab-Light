- Timer 使用
```
#include <TimerOne.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Timer1.initialize(5000); // us
  Timer1.attachInterrupt(myprint);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void myprint() {
  Serial.println("call myprint");  
}
```
