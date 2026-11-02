#include "Light.h"
#include <random>

// Utilisation du nouveau constructeur de la classe mère pour fixer la base de temps à 2
Light::Light() : Sensor("Light", 2) {}

Light::Light(const Light &light) : Sensor(light) {}

Light& Light::operator=(const Light &light) {
    this->Sensor::operator=(light);
    return *this;
}

Light::~Light() {}

void Light::execute(int mode) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);
    
    delete this->currentData;
    
    // On crée une nouvelle donnée de type BOOLEAN avec le préfixe "Light"
    bool isLightOn = d(gen);
    this->currentData = new SensorData<bool>(isLightOn, "Light");
    
    if (this->server != nullptr) {
        server->receive(this->currentData, this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}