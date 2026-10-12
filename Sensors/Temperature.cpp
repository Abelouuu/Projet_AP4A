//
// Created by Myotte-Duquet on 12/10/2026.
//

#include "Temperature.h"

#include <random>

Temperature::Temperature(): Sensor("Temperature") {
    
}

Temperature::Temperature(const Temperature &Tempsensor): Sensor(Tempsensor){
}


Temperature& Temperature::operator=(const Temperature &Tempsensor) {
    if (this != &Tempsensor) {
        this->Sensor::operator=(Tempsensor);
    }
    return *this;
}

Temperature::~Temperature(){}


void Temperature::execute(int mode) {
    float randomvalue;
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distribution(50.0f, 5000.0f);

    randomvalue = distribution(gen);
    this->measure = std::to_string(randomvalue)+"C";
    if (this->server != nullptr) {
        server->receive(this->measure, this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}

Sensor* Temperature::clone() {
    return new Temperature(*this);
}