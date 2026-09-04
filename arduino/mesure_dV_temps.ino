// Déclarations des pins analogiques
const int pinA0 = A0; // Pour la thermistance (pont de Wheatstone)
const int pinA1 = A1;

// Référence de tension (par défaut 5V pour Arduino Uno)
const float vRef = 5.0;

// Variables globales pour stocker les tensions
float tensionUA0 = 0.0; // Tension mesurée sur A0
float tensionUA1 = 0.0; // Tension mesurée sur A1
float tensionTh = 0.0;  // Différence de tension (thermistance)

// Variables pour l'énergie et le temps
unsigned long startTime = 0;   // Temps de démarrage du chronomètre
unsigned long elapsedTime = 0; // Temps écoulé

void setup() {
  // Configuration de la résolution ADC
  analogReadResolution(12); // Définit la résolution ADC sur 12 bits

  // Initialisation de la communication série pour afficher les résultats
  Serial.begin(9600);
  // Initialiser le chronomètre
  startTime = millis(); // Enregistre le temps au démarrage
}

void loop() {
  // Lecture des valeurs analogiques
  int valeurUA0 = analogRead(pinA0);
  int valeurUA1 = analogRead(pinA1);

  // Conversion des valeurs analogiques en tensions (en volts)
  tensionUA0 = (valeurUA0 * vRef) / 4095.0;
  tensionUA1 = (valeurUA1 * vRef) / 4095.0;

  // Calcul de la différence de tension (thermistance)
  tensionTh = tensionUA1 - tensionUA0;

  // Calcul du temps écoulé
  unsigned long currentTime = millis();
  elapsedTime = (currentTime - startTime) / 1000.0;

  // Affichage des résultats sur le moniteur série
  Serial.print(tensionTh);
  Serial.print(",");
  Serial.println(elapsedTime); // Affichage en secondes

  // Pause de 1 seconde entre chaque mesure
  delay(1000);
}
