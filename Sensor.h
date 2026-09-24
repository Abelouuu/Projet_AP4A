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
        int id;
        std::string type;
        float measure;
        Server *server;

        static int idcounter;
    public:
      Sensor();
      Sensor(const Sensor &s);
      virtual ~Sensor();

      Sensor& operator=(const Sensor& s);
      friend std::ostream& operator<<(std::ostream& os, const Sensor& s);

      virtual void update();

      virtual void execute();
};
#endif //SENSOR_H
