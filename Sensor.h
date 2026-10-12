//
// Created by abel6 on 9/24/2026.
//

#ifndef SENSOR_H
#define SENSOR_H

#include "Server.h"
#include <iostream>
#include <string>

class Sensor {
private:
    int currentTime;
    int internalTimeBase;
    static int idcounter;
protected:
    int id;
    std::string measure;
    Server *server;
    std::string type;

public:
    Sensor();
    Sensor(std::string type);
    Sensor(const Sensor &s);
    virtual ~Sensor();

    Sensor& operator=(const Sensor& s);
    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);

    virtual void update(int mode);
    virtual void execute(int mode)=0;
    virtual Sensor* clone()=0;

    void setServer(Server* s);
};
#endif //SENSOR_H