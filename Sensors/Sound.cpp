//
// Created by Myotte-Duquet on 12/10/2026.
//

#include "Sound.h"

#include <iomanip>
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

     std::uniform_real_distribution<float> distribution(30.0f, 90.0f);

     randomvalue = distribution(gen);
     std::ostringstream approxvalue;
     approxvalue << std::fixed << std::setprecision(2) << randomvalue;
     this->measure = approxvalue.str()+ "Db";
     if (this->server != nullptr) {
          server->receive(this->measure, this->type, mode);
     } else {
          std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
     }
}

Sensor* Sound::clone() {
     return new Sound(*this);
}