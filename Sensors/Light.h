#ifndef LIGHT_H
#define LIGHT_H

#include "../Sensor.h"

class Light: public Sensor {
public:
    Light();
    Light(const Light& light);
    Light& operator=(const Light& light);
    ~Light() override;
    
    // Redéfinition de la méthode virtuelle pure de Sensor
    void execute(int mode) override;
};

#endif //LIGHT_H