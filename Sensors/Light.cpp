//
// Created by abel6 on 10/12/2026.
//

#include "Light.h"
#include <random>

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
    float randomValue;
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distribution(50.0f, 5000.0f);

    randomValue = distribution(gen);

    this->measure = std::to_string(randomValue) + " LUX";

    if (this->server != nullptr) {
        server->receive(this->measure, this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}
