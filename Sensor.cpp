//
// Created by abel6 on 9/24/2026.
//

#include "Sensor.h"
#include <iostream>

int Sensor::idcounter = 0;

Sensor::Sensor() {
  this->idcounter++;
  this->id = compteurId;
  this->type = "DefaultSensor";
  this->measure = 0f;
  this->server = nullptr;
}

Sensor::Sensor(const Sensor &s){
  idcounter++;
  this->id = idcounter;
  this->type = s.type;
  this->measure = s.measure;
  this->server = s.server;
}

Snesor& Sensor::operator=(const Sensor &s) {
  if (this != &s) {
    this->type = s.type;
    this->measure = s.measure;
    this->server = s.server;
  }
  return *this;
}
Sensor::~Sensor() {}

std::ostream& operator<<(std::ostream& os, const Sensor& s) {
  os << "[Capteur " << s.type << " | ID: " << s.id << "] Mesure : " << s.measure;
  return os;
}