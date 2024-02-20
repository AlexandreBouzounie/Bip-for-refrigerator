#include <Adafruit_LEDBackpack.h>                                // Inclut la bibliothèque "Adafruit_LEDBackpack" poour utiliser l'afficheur 7 segments à 4 digits I2C
Adafruit_7segment led_display1 = Adafruit_7segment();            // Définit le type de l'afficheur 7 segments à 4 digits I2C
const int STMP = A3;                                             // Crée une constante "STMP" de valeur "A3"
const int VCCBUZZER = 2;                                         // Crée une constante "VCCBUZZER" de valeur "2"
int c = 0;                                                       // Crée une variable "c" de valeur 0
int tmax = 6;                                                    // Crée une variable "tmin" de valeur 6
int tmin = 0;                                                    // Crée une variable "tmin" de valeur 0
void setup() {                                                   // Dans la fonction "setup()"...
  led_display1.begin(112);                                       // La vitesse du signal de l'afficheur 7 segments à 4 digits I2C est de 112
  pinMode(STMP, INPUT);                                          // Définit la broche A3 de l'Arduino UNO en entrée
  pinMode(VCCBUZZER, OUTPUT);                                    // Définit la broche 2 de la'Arduino UNO en sortie
  digitalWrite(VCCBUZZER, LOW);                                  // Met la broche 2 à l'état bas (arrêté)
}                                                                // Fin de la fonction "setup()"
void loop() {                                                    // Dans la fonction "loop()"...
  maj();                                                         // Exécuter la fonction "maj()" (précisée plus tard)
  while (c > tmax) {                                             // Tant que la variable "c" est forcément supérieure à la variable "tmax"...
    digitalWrite(VCCBUZZER, HIGH);                               // Met la broche 2 à l'état haut (allumé)
    maj();                                                       // Exécuter la fonction "maj()"
    delay(500);                                                  // Attendre 0,5 secondes
    digitalWrite(VCCBUZZER, LOW);                                // Met la broche 2 à l'état bas (arrêté)
    maj();                                                       // Exécuter la fonction "maj()"
    delay(500);                                                  // Attendre 0,5 secondes
  }                                                              // Fin de la boucle while
  while (c <= tmin) {                                            // Tant que la variable "c" est inférieure ou égale à la variable "tmin"...
    digitalWrite(VCCBUZZER, HIGH);                               // Met la broche 2 à l'état haut (allumé)
    maj();                                                       // Exécuter la fonction "maj()"
    delay(250);                                                  // Attendre 0,25 secondes
    digitalWrite(VCCBUZZER, LOW);                                // Met la broche 2 à l'état bas (arrêté)
    maj();                                                       // Exécuter la fonction "maj()"
    delay(750);                                                  // Attendre 0,25 secondes
  }                                                              // Fin de la boucle while
  delay(500);                                                    // Attendre 0,5 secondes
}                                                                // Fin de la fonction "loop()"
void maj() {                                                     // Dans la fonction "maj()"...
  c = map(((analogRead(STMP) - 20) * 3.04), 0, 1023, -40, 125);  // Mettre à jour la variable "c"
  led_display1.writeDisplay();                                   // Effacer l'Afficheur l'afficheur 7 segments à 4 digits I2C
  led_display1.print(c);                                         // Afficher la variable "c" sur l'afficheur 7 segments à 4 digits I2C
}                                                                // Fin de la fonction "maj()"
