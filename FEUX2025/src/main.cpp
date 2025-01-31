// /*
//   Titre      : Titre du programme
//   Auteur     : Boladji ODELOUI
//   Date       : 30/01/2025
//   Description: Une description du programme
//   Version    : 0.0.1
// */

#include <Arduino.h>
#include <Wire.h>

const int my_intersection[4][3] = {
    {13, 15, 32}, // Intersection A - Rouge, Jaune, Vert
    {12, 2, 33},  // Intersection B - Rouge, Jaune, Vert
    {14, 26, 18}, // Intersection C - Rouge, Jaune, Vert
    {27, 25, 19}  // Intersection D - Rouge, Jaune, Vert
};

// Classe représentant un Feu Tricolore
class Feux
{
private:
  int brocheRouge;
  int brocheJaune;
  int brocheVerte;

public:
  // Constructeur initialisant les broches
  Feux(int broche_r, int broche_j, int broche_v)
      : brocheRouge(broche_r), brocheJaune(broche_j), brocheVerte(broche_v) {}

 // Fonction pour declarer les différentes broches
   int begin()
  {
    pinMode(brocheRouge, OUTPUT);
    pinMode(brocheJaune, OUTPUT);
    pinMode(brocheVerte, OUTPUT);
    return (0);
  }

  // Fonction pour allumer et eteindre les LED
  int startRed()
  {
    digitalWrite(brocheRouge, HIGH);
    digitalWrite(brocheJaune, LOW);
    digitalWrite(brocheVerte, LOW);
    return (0);
  }

  int startYellow()
  {
    digitalWrite(brocheRouge, LOW);
    digitalWrite(brocheJaune, HIGH);
    digitalWrite(brocheVerte, LOW);
    return (0);
  }

  int startGreen()
  {
    digitalWrite(brocheRouge, LOW);
    digitalWrite(brocheJaune, LOW);
    digitalWrite(brocheVerte, HIGH);
    return (0);
  }

  int offLight()
  {
    digitalWrite(brocheRouge, LOW);
    digitalWrite(brocheJaune, LOW);
    digitalWrite(brocheVerte, LOW);
    return (0);
  }

  // Méthode pour faire clignoter le feu vert
   int blink_ledGreen(int temp, int k)
  {
    for (int j = 0; j < temp; j++)
    {
      digitalWrite(brocheVerte, HIGH);
      delay(k);
      digitalWrite(brocheVerte, LOW);
      delay(k);
    }
    return (0);
  }
};

// Création d'instances de Feux pour chaque intersection

Feux isfeu_a(my_intersection[0][0], my_intersection[0][1], my_intersection[0][2]);
Feux isfeu_b(my_intersection[1][0], my_intersection[1][1], my_intersection[1][2]);
Feux isfeu_c(my_intersection[2][0], my_intersection[2][1], my_intersection[2][2]);
Feux isfeu_d(my_intersection[3][0], my_intersection[3][1], my_intersection[3][2]);

void setup()
{
  Serial.begin(9600); // Initialisation du moniteur série
  isfeu_a.begin();
  isfeu_b.begin();
  isfeu_c.begin();
  isfeu_d.begin();
}

void loop()
{
  isfeu_a.startGreen();
  isfeu_b.startGreen();
  isfeu_c.startRed();
  isfeu_d.startRed();
  delay(5000);

  isfeu_a.blink_ledGreen(3, 500);
  isfeu_b.blink_ledGreen(3, 500);

  isfeu_a.startYellow();
  isfeu_b.startYellow();
  delay(2000);

  isfeu_a.startRed();
  isfeu_b.startRed();
  isfeu_c.startGreen();
  isfeu_d.startGreen();
  delay(5000);

  isfeu_c.blink_ledGreen(3, 500);
  isfeu_d.blink_ledGreen(3, 500);

  isfeu_c.startYellow();
  isfeu_d.startYellow();
  delay(2000);

  isfeu_c.startRed();
  isfeu_d.startRed();
}

