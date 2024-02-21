/*
test1tmp36.ino
© Donkey Kong Informatique
This coding as been created and modified by DKI (@AlexandreBouzounie in GitHub https://github.com/AlexandreBouzounie).
This coding is in Arduino Web Editor and GitHub depot (https://github.com/AlexandreBouzounie/Bip-for-refrigerator/blob/main/test1tmp36.ino).
The general depot for Bip for refrigerator is in https://github.com/AlexandreBouzounie/Bip-for-refrigerator .
*/

float c = 0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  digitalWrite(12, HIGH);
  Serial.println("------------------------------------------------------------------------");
  Serial.println("test1tmp36.ino");
  Serial.println("© Donkey Kong Informatique");
  Serial.println("This coding as been created and modified by DKI (@AlexandreBouzounie in GitHub https://github.com/AlexandreBouzounie).");
  Serial.println("This coding is in Arduino Web Editor and GitHub depot (https://github.com/AlexandreBouzounie/Bip-for-refrigerator/blob/main/test1tmp36.ino).");
  Serial.println("The general depot for Bip for refrigerator is in https://github.com/AlexandreBouzounie/Bip-for-refrigerator .");
  delay(2000);
  Serial.println("-------------------------------LOADING...-------------------------------");
  delay(5000);
  Serial.println("---------------------------------READY?---------------------------------");
  delay(3000);
}

void loop() {
  c = ((((digitalRead(13) * 5.0) / 1024.0) - 0.5) * 100);
  Serial.println(c);
  delay(500);
}
