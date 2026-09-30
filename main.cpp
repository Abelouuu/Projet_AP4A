#include <iostream>
#include <filesystem>
#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"
int main() {
    Server serv1;

    Sensor sensor1;
    sensor1.setServer(&serv1);
    Scheduler schedule;
    schedule.add_sensor(&sensor1);

    schedule.simulation(20);

    return 0;
}