//
// Created by abel6 on 10/12/2026.
//

#ifndef LIGHT_H
#define LIGHT_H
#include "../Sensor.h"


class Light: public Sensor {
    public:
    Light();
    Light(const Light& light);

    Light& operator=(const Light& light);

    void execute(int mode) override;
    ~Light();
};



#endif //LIGHT_H
