#include <Adafruit_LEDBackpack.h>

Adafruit_7segment led_display1 = Adafruit_7segment();

const int STMP = A3;
const int SCL7SEG = A5;
const int SDA7SEG = A4;
const int VCCBUZZER = 2;
int c = 0;
int tmax = 6;

void setup() {
  led_display1.begin(112);
  pinMode(STMP, INPUT);
  pinMode(VCCBUZZER, OUTPUT);
  digitalWrite(VCCBUZZER, LOW);
}

void loop() {
  meatselcd();
  while (c > tmax) {
    digitalWrite(VCCBUZZER, HIGH);
    meatselcd();
    delay(500);
    digitalWrite(VCCBUZZER, LOW);
    meatselcd();
    delay(500);
  }
  if (c = 0) {
    for (int i; i = 7; i++) {
      digitalWrite(VCCBUZZER, HIGH);
      meatselcd();
      delay(500);
      digitalWrite(VCCBUZZER, LOW);
      meatselcd();
      delay(500);
    }
  }
  delay(500);
}

void meatselcd() {
  c = map(((analogRead(STMP) - 20) * 3.04), 0, 1023, -40, 125);
  led_display1.writeDisplay();
  led_display1.print(c);
}
