#ifndef AP4ATP1_TEMPERATURE_H
#define AP4ATP1_TEMPERATURE_H

#include "../Sensor.h"

class Temperature : public Sensor {
private:
    float lastTemp = 10.0f;
public:
    Temperature();
    Temperature(const Temperature& Tempsensor);
    Temperature& operator=(const Temperature& Tempsensor);
    ~Temperature() override; // Ajout du mot-clé override par bonne pratique

    void execute(int mode) override;
};

#endif //AP4ATP1_TEMPERATURE_H