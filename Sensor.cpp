//
// Created by abel6 on 9/24/2026.
//

#include "Sensor.h"
#include <iostream>
#include <random>

int Sensor::idcounter = 0;

Sensor::Sensor()
    : id(++idcounter), type("DefaultSensor"), measure(0.0f), server(nullptr), currentTime(0), internalTimeBase(1) {

}

Sensor::Sensor(const Sensor &s)
    : id(++idcounter), type(s.type), measure(s.measure), server(s.server), currentTime(s.currentTime), internalTimeBase(s.internalTimeBase) {
}

Sensor& Sensor::operator=(const Sensor &s) {
  if (this != &s) {
    this->type = s.type;
    this->measure = s.measure;
    this->server = s.server;
    this->currentTime = s.currentTime;
    this->internalTimeBase = s.internalTimeBase;
  }
  return *this;
}

Sensor::~Sensor() {}

void Sensor::setServer(Server* s) {
    this->server = s;
}

std::ostream& operator<<(std::ostream& os, const Sensor& s) {
  os << "[Capteur " << s.type << " | ID: " << s.id << "] Mesure : " << s.measure;
  return os;
}

void Sensor::update(int mode) {
  currentTime++;
  if (currentTime >= internalTimeBase) {
    currentTime = 0;
    this->execute(mode);
  }
}

void Sensor::execute(int mode) {
  // Utilisation de static pour que le générateur aléatoire ne soit instancié qu'une seule fois
  // et ne génère pas la même valeur si execute() est appelé très vite plusieurs fois.
  static std::random_device rd;
  static std::mt19937 gen(rd());

  // Génère un nombre à virgule flottante entre 0.0 et 30.0
  std::uniform_real_distribution<float> distribution(0.0f, 30.0f);

  this->measure = distribution(gen);

  if (this->server != nullptr) {
      server->receive(this->measure, this->type, mode);
  } else {
      std::cerr << "Attention : Capteur " << this->id << " n'est lié à aucun serveur !" << std::endl;
  }
}