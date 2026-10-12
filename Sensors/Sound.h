//
// Created by Myotte-Duquet on 12/10/2026.
//

#ifndef AP4ATP1_SOUND_H
#define AP4ATP1_SOUND_H
#include "../Sensor.h"


class Sound : public Sensor{
public:
    Sound();
    Sound(const Sound& Soundsensor);
    Sound& operator=(const Sound& Soundsensor);
    ~Sound();

    void execute(int mode) override;
    Sensor* clone() override;
};



#endif //AP4ATP1_SOUND_H