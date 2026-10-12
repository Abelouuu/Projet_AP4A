//
// Created by abel6 on 9/24/2026.
//

#include "Sensor.h"
#include <iostream>
#include <random>

int Sensor::idcounter = 0;

Sensor::Sensor()
    : id(++idcounter), type("DefaultSensor"), measure(""), server(nullptr), currentTime(0), internalTimeBase(1) {

}

Sensor::Sensor(const Sensor &s)
    : id(++idcounter), type(s.type), measure(s.measure), server(s.server), currentTime(s.currentTime), internalTimeBase(s.internalTimeBase) {
}

Sensor::Sensor(std::string type): id(++idcounter), type(type), measure(""), server(nullptr), currentTime(0), internalTimeBase(1) {
    this->type = type;
    if (type == "Temperature") {
        this->internalTimeBase = 3;
    }
    if (type == "Light") {
        this->internalTimeBase = 2;
    }
    if (type == "Sound") {
        this->internalTimeBase = 4;
    }
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
