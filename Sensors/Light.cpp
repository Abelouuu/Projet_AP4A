#include "Light.h"
#include <random>

// Utilisation du nouveau constructeur de la classe mère pour fixer la base de temps à 2 cycles
Light::Light() : Sensor("Light", 2) {}

Light::Light(const Light &light) : Sensor(light) {}

Light& Light::operator=(const Light &light) {
    this->Sensor::operator=(light);
    return *this;
}

Light::~Light() {}

void Light::execute(int mode) {
    // Générateur aléatoire déclaré en static pour n'être initialisé qu'une seule fois
    static std::random_device rd;
    static std::mt19937 gen(rd());
    // Loi de Bernoulli (probabilité 50/50) pour simuler l'état allumé ou éteint
    std::bernoulli_distribution d(0.5);

    // Libération de l'ancienne mesure avant d'allouer la nouvelle pour éviter toute fuite mémoire
    delete this->currentData;

    // On crée une nouvelle donnée de type BOOLEAN avec le préfixe "Light"
    bool isLightOn = d(gen);
    this->currentData = new SensorData<bool>(isLightOn, "Light");

    // Vérification de sécurité sur le pointeur avant l'envoi au serveur
    if (this->server != nullptr) {
        server->receive(this->currentData, this->type, mode);
    } else {
        std::cerr << "Attention : Capteur " << this->id << " n'est lie a aucun serveur !" << std::endl;
    }
}