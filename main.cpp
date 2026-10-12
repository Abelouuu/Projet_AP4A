#include "Sensors/Light.h"
#include "Sensor.h"
#include "Scheduler.h"
#include "Sensors/Sound.h"
#include "Sensors/Temperature.h"

int main() {
    Server serv1;

    Light lightSensor1;
    Sound SoundSensor;
    Temperature tempsensor;
    lightSensor1.setServer(&serv1);
    SoundSensor.setServer(&serv1);
    tempsensor.setServer(&serv1);
    Scheduler schedule;
    schedule.add_sensor(&lightSensor1);
    schedule.add_sensor(&SoundSensor);
    schedule.add_sensor(&tempsensor);
    schedule.add_server(&serv1);

    schedule.simulation(10);

    return 0;
}
