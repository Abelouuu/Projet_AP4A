#include "Sensors/Light.h"
#include "Sensor.h"
#include "Scheduler.h"
int main() {
    Server serv1;

    Light lightSensor1;
    lightSensor1.setServer(&serv1);
    Scheduler schedule;
    schedule.add_sensor(&lightSensor1);

    schedule.simulation(20);

    return 0;
}