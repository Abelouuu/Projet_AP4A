#ifndef LIGHT_H
#define LIGHT_H

#include "../Sensor.h"

class Light: public Sensor {
public:
    Light();
    Light(const Light& light);
    Light& operator=(const Light& light);
    ~Light() override; // Ajout du mot-clé override par bonne pratique
    
    void execute(int mode) override;
};

#endif //LIGHT_H