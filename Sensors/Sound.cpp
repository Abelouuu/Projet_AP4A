#include "Sound.h"
#include <random>

// Utilisation du nouveau constructeur de la classe mère pour fixer la base de temps à 4
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
     std::uniform_real_distribution<float> distribution(30.0f, 90.0f);

     // Libération de la mémoire de la précédente mesure
     delete this->currentData;

     // Création d'une nouvelle donnée générique de type FLOAT avec l'unité "Db"
     float randomvalue = distribution(gen);
     this->currentData = new SensorData<float>(randomvalue, "Db");

     if (this->server != nullptr) {
          // Envoi au serveur (modifie la signature dans Server si tu passes à un Data*)
          server->receive(this->currentData->toString(), this->type, mode);
     } else {
          std::cerr << "Attention : Capteur " << this->id << " n'est lie a aucun serveur !" << std::endl;
     }
}