#ifndef SENSOR_H
#define SENSOR_H

#include "Server.h"
#include "Data/data.h" // Inclusion de la nouvelle classe générique
#include <iostream>
#include <string>

class Sensor {
private:
    int currentTime;
    int internalTimeBase;
    static int idcounter;

protected:
    int id;
    Data* currentData; // Remplacement : stocke un pointeur générique au lieu d'un string
    Server *server;
    std::string type;

    // Constructeur protégé pour initialiser directement la base de temps depuis les classes filles
    Sensor(std::string type, int timeBase);

public:
    Sensor();
    Sensor(const Sensor &s);
    virtual ~Sensor();

    Sensor& operator=(const Sensor& s);
    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);

    virtual void update(int mode);
    virtual void execute(int mode) = 0;

    void setServer(Server* s);
};

#endif //SENSOR_H