/*
test2tmp36.ino
© Donkey Kong Informatique
This coding as been created and modified by DKI (@alexbouz in Arduino Web Editor https://github.com/AlexandreBouzounie).
This coding is in Arduino Web Editor (https://app.arduino.cc/sketches/7f28dfe1-8f93-4dd8-9efc-93bd8fa06e3f) and GitHub depot.
The general depot for Bip for refrigerator is in https://github.com/AlexandreBouzounie/Bip-for-refrigerator .
*/

#define ADC_VREF 5.0
#define ADC_RESOLUTION 1024.0
#define PIN_TMP36 13

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcVal = digitalRead(PIN_TMP36);
  float voltage = adcVal * (ADC_VREF / ADC_RESOLUTION);
  float tempC = (voltage - 0.5) * 100;
  float tempF = tempC * 1.8;
  Serial.print("TMP36 Temperature: ");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.print("  ~  ");
  Serial.print(tempF);
  Serial.println("°F");
  delay(500);
}
