//
// Created by abel6 on 10/12/2026.
//

#include "Light.h"
#include <random>
#include <iomanip>

Light::Light(): Sensor("Light") {

}

Light::Light(const Light &light): Sensor(light) {

}

Light &Light::operator=(const Light &light) {
    this->Sensor::operator=(light);
    return *this;
}

Light::~Light() {

}

Sensor* Light::clone() {
    return new Light(*this);
}

void Light::execute(int mode) {
    bool isLightOn;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::bernoulli_distribution d(0.5);

    isLightOn = d(gen);

    if (isLightOn) {
        this->measure = "Light ON";
    } else {
        this->measure = "Light OFF";
    }

    if (this->server != nullptr) {
        server->receive(this->measure, this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}
