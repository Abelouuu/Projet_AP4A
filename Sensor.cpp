#include "Sensor.h"

int Sensor::idcounter = 0;

Sensor::Sensor()
    : id(++idcounter), type("DefaultSensor"), currentData(nullptr), server(nullptr), currentTime(0), internalTimeBase(1) {
}

// Nouveau constructeur optimisé pour les classes filles
Sensor::Sensor(std::string type, int timeBase)
    : id(++idcounter), type(type), currentData(nullptr), server(nullptr), currentTime(0), internalTimeBase(timeBase) {
}

Sensor::Sensor(const Sensor &s)
    : id(++idcounter), type(s.type), currentData(nullptr), server(s.server), currentTime(s.currentTime), internalTimeBase(s.internalTimeBase) {
    // Attention : on ne copie pas le pointeur Data, on réinitialisera la mesure lors du premier execute()
}

Sensor& Sensor::operator=(const Sensor &s) {
    if (this != &s) {
        this->type = s.type;
        this->server = s.server;
        this->currentTime = s.currentTime;
        this->internalTimeBase = s.internalTimeBase;
    }
    return *this;
}

Sensor::~Sensor() {
    delete currentData; // Libération de la mémoire de la donnée générique
}

void Sensor::setServer(Server* s) {
    this->server = s;
}

std::ostream& operator<<(std::ostream& os, const Sensor& s) {
    os << "[Capteur " << s.type << " | ID: " << s.id << "] Mesure : ";
    if (s.currentData != nullptr) {
        os << s.currentData->toString();
    } else {
        os << "Aucune";
    }
    return os;
}

void Sensor::update(int mode) {
    currentTime++;
    if (currentTime >= internalTimeBase) {
        currentTime = 0;
        this->execute(mode);
    }
}