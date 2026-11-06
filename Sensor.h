#ifndef SENSOR_H
#define SENSOR_H

#include "Server.h"
#include "Data/data.h" // Inclusion de la nouvelle classe générique
#include <iostream>
#include <string>

class Sensor {
private:
    int currentTime;
    int internalTimeBase; // Période d'échantillonnage propre au capteur
    static int idcounter; // Compteur statique partagé pour générer un ID unique par instance

protected:
    int id;
    Data* currentData;
    Server *server;
    std::string type;

    // Constructeur protégé pour initialiser directement la base de temps depuis les classes filles
    Sensor(std::string type, int timeBase);

public:
    // Forme canonique de Coplien
    Sensor();
    Sensor(const Sensor &s);
    virtual ~Sensor(); // Destructeur virtuel pour gérer le polymorphisme
    Sensor& operator=(const Sensor& s);

    // Surcharge de l'opérateur de flux pour afficher facilement l'état d'un capteur
    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);

    virtual void update(int mode);
    virtual void execute(int mode) = 0; // Méthode virtuelle pure : rend la classe Sensor abstraite

    void setServer(Server* s);
};

#endif //SENSOR_H