//
// Created by Myotte-Duquet on 12/10/2026.
//

#include "Sound.h"

#include <random>

Sound::Sound(): Sensor("Sound") {}

Sound::Sound(const Sound &Soundsensor) : Sensor(Soundsensor){
}

Sound& Sound::operator=(const Sound &Soundsensor) {
     if (this != &Soundsensor) {
          this->Sensor::operator=(Soundsensor);
     }
     return *this;
}

Sound::~Sound() {}


void Sound::execute(int mode) {
     float randomvalue;
     static std::random_device rd;
     static std::mt19937 gen(rd());

     std::uniform_real_distribution<float> distribution(50.0f, 5000.0f);

     randomvalue = distribution(gen);
     this->measure = std::to_string(randomvalue )+ "Db";
     if (this->server != nullptr) {
          server->receive(this->measure, this->type, mode);
     } else {
          std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
     }
}

Sensor* Sound::clone() {
     return new Sound(*this);
}