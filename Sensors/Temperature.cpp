#include "Temperature.h"
#include <iomanip>
#include <random>

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
    std::uniform_real_distribution<float> distribution(-30.0f, 50.0f);

    // On libère l'ancienne mesure pour éviter les fuites mémoire
    delete this->currentData;

    // On crée une nouvelle donnée de type FLOAT avec l'unité "C"
    float randomvalue = distribution(gen);
    this->currentData = new SensorData<float>(randomvalue, "C");

    if (this->server != nullptr) {
        // Le serveur recevra le pointeur polymorphe Data*
        // N'oublie pas de modifier la signature de server->receive() dans Server.h et Server.cpp !
        server->receive(this->currentData->toString(), this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
    }
}