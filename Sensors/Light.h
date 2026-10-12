//
// Created by abel6 on 10/12/2026.
//

#ifndef LIGHT_H
#define LIGHT_H
#include "../Sensor.h"


class Light: public Sensor {

    public:
    Light();
    Light(const Light&);

    Light& operator=(const Light&);


    ~Light();
};



#endif //LIGHT_H
