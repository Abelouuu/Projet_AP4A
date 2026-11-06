#ifndef AP4ATP1_TEMPERATURE_H
#define AP4ATP1_TEMPERATURE_H

#include "../Sensor.h"

class Temperature : public Sensor {
private:
    // Mémorise la température précédente pour éviter des sauts de valeurs incohérents
    float lastTemp = 10.0f;
public:
    Temperature();
    Temperature(const Temperature& Tempsensor);
    Temperature& operator=(const Temperature& Tempsensor);
    ~Temperature() override;

    void execute(int mode) override;
};

#endif //AP4ATP1_TEMPERATURE_H