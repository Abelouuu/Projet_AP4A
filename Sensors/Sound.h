#ifndef AP4ATP1_SOUND_H
#define AP4ATP1_SOUND_H

#include "../Sensor.h"

class Sound : public Sensor {
private:
    float lastSound = 50.0f;
public:
    Sound();
    Sound(const Sound& Soundsensor);
    Sound& operator=(const Sound& Soundsensor);
    ~Sound() override; // Ajout du mot-clé override par bonne pratique

    void execute(int mode) override;
};

#endif //AP4ATP1_SOUND_H