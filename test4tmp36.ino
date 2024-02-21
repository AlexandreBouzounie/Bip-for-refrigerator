/*
test4tmp36.ino
© Donkey Kong Informatique
This coding as been created and modified by DKI (@alexbouz in Arduino Web Editor).
This coding is in Arduino Web Editor (https://app.arduino.cc/sketches/alexbouz/15da6970-5aa7-4cd1-a2e2-4972068b9838/preview) and GitHub depot.
*/

float c = 0;
float f = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  digitalWrite(12, HIGH);
  digitalWrite(2, HIGH);
  Serial.println("------------------------------------------------------------------------");
  Serial.println("test1tmp36.ino");
  Serial.println("© Donkey Kong Informatique");
  Serial.println("This coding as been created and modified by DKI (@alexbouz in Arduino Web Editor).");
  Serial.println("This coding is in Arduino Web Editor (https://app.arduino.cc/sketches/alexbouz/15da6970-5aa7-4cd1-a2e2-4972068b9838/preview) and GitHub depot");
  delay(2000);
  Serial.println("-------------------------------LOADING...-------------------------------");
  delay(5000);
  Serial.println("---------------------------------READY?---------------------------------");
  delay(3000);
}

void loop() {
  c = (digitalRead(13) - 500) / 10;
  f = c * 1.8;
  Serial.println();
  Serial.print("Temperature in Celcius: ");
  Serial.print(c);
  Serial.println("°C");
  Serial.print("Temperature in Farenheit: ");
  Serial.print(f);
  Serial.print("°F");
  delay(500);
}
