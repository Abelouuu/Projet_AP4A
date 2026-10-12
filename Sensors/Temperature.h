//
// Created by Myotte-Duquet on 12/10/2026.
//

#ifndef AP4ATP1_TEMPERATURE_H
#define AP4ATP1_TEMPERATURE_H
#include "../Sensor.h"
#include <string>

class Temperature : public Sensor{

public:
    Temperature();
    Temperature(const Temperature& Tempsensor);
    Temperature& operator=(const Temperature& Tempsensor);
    ~Temperature();

    void execute(int mode) override;
    Sensor* clone() override;

};


#endif //AP4ATP1_TEMPERATURE_H