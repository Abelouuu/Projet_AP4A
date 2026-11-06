#include "Sound.h"
#include <random>
#include <algorithm>

// Utilisation du nouveau constructeur de la classe mère pour fixer la base de temps à 4 cycles
Sound::Sound() : Sensor("Sound", 4) {}

Sound::Sound(const Sound &Soundsensor) : Sensor(Soundsensor) {}

Sound& Sound::operator=(const Sound &Soundsensor) {
     if (this != &Soundsensor) {
          this->Sensor::operator=(Soundsensor);
     }
     return *this;
}

Sound::~Sound() {}

void Sound::execute(int mode) {
     static std::random_device rd;
     static std::mt19937 gen(rd());
     // Loi normale centrée en 0 (écart-type de 3 dB) pour créer une fluctuation progressive
     std::normal_distribution<float> pas(0.0f, 3.0f);

     const float moyenne = 55.0f;
     const float rappel  = 0.05f;

     // Calcul de la nouvelle valeur par retour à la moyenne et sélection entre 30 et 90 dB
     this->lastSound += rappel * (moyenne - lastSound) + pas(gen);
     this->lastSound = std::clamp(lastSound, 30.0f, 90.0f);

     // Remplacement de l'ancienne mesure par la nouvelle instance générique float
     delete this->currentData;
     this->currentData = new SensorData<float>(lastSound, "Db");

     if (this->server != nullptr) {
          // Envoi au serveur
          server->receive(this->currentData, this->type, mode);
     } else {
          std::cerr << "Attention : Capteur " << this->id << " n'est lie a aucun serveur !" << std::endl;
     }
}