#include "Temperature.h"
#include <random>
#include <algorithm>

// Utilisation du nouveau constructeur de la classe mère pour fixer la base de temps à 3
Temperature::Temperature() : Sensor("Temperature", 3) {}

Temperature::Temperature(const Temperature &Tempsensor) : Sensor(Tempsensor) {}

Temperature& Temperature::operator=(const Temperature &Tempsensor) {
    if (this != &Tempsensor) {
        this->Sensor::operator=(Tempsensor);
    }
    return *this;
}

Temperature::~Temperature() {}

void Temperature::execute(int mode) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<float> pas(0.0f, 0.3f);

    const float moyenne = 10.0f;
    const float rappel  = 0.01f;

    // Nouvelle valeur = ancienne + retour vers la moyenne + petit bruit
    lastTemp += rappel * (moyenne - lastTemp) + pas(gen);
    lastTemp = std::clamp(lastTemp, -30.0f, 50.0f);

    delete this->currentData;
    this->currentData = new SensorData<float>(lastTemp, "C");

    if (this->server != nullptr) {
        // Le serveur recevra le pointeur polymorphe Data*
        // N'oublie pas de modifier la signature de server->receive() dans Server.h et Server.cpp !
        server->receive(this->currentData->toString(), this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}