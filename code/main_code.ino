/*
사용 부품
- 아두이노 나노
- 서보 모터 2개
- 레이저 모듈 1개
- 슬라이드 스위치 1개
*/
#include <Servo.h>

Servo BOT;
Servo TOP;

// pin number setting
int pin_bot = 12;
int pin_top = 11;
int pin_laser = 13;
int pin_slide_switch = 2;

int degree_bot_min = 0;    // 하단 모터 각도 최소값
int degree_bot_max = 180;  // 하단 모터 각도 최대값
int degree_top_min = 0;    // 상단 모터 각도 최소값
int degree_top_max = 180;  // 상단 모터 각도 최대값
int delay_min = 0;         //delay minimum
int delay_max = 1000;      //delay maximum

void setup() {
  pinMode(pin_laser, OUTPUT);
  digitalWrite(pin_laser, LOW);
  pinMode(pin_slide_switch, INPUT_PULLUP);
  BOT.attach(pin_bot);
  TOP.attach(pin_top);
  BOT.write(0);
  TOP.write(0);
}

void loop() {// 하단, 상단 모터 각도 및 각도 변경 주기 시간 모두 랜덤으로 지정
  if (digitalRead(pin_slide_switch) == 0) {
    randomSeed(millis());
    int degree_bot = random(degree_bot_min, degree_bot_max);
    int degree_top = random(degree_top_min, degree_top_max);
    int delay_random = random(delay_min, delay_max);
    digitalWrite(pin_laser, HIGH);
    BOT.write(degree_bot);
    TOP.write(degree_top);
    delay(delay_random);
  } else {
    digitalWrite(pin_laser, LOW);
    BOT.write(0);
    TOP.write(0);
  }
}