#include "Sensors/Light.h"
#include "Sensor.h"
#include "Scheduler.h"
#include "Sensors/Sound.h"
#include "Sensors/Temperature.h"

int main() {
    Server serv1 ;

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

    // La gestion de l'interface utilisateur (console) se fait en dehors du Scheduler
    int mode = -1;
    while (mode != 1 && mode != 0) {
        std::cout << "Mode d'affichage Console(0) ou File(1): " << std::endl;
        std::cin >> mode;
        if (mode != 1 && mode != 0) {
            std::cout << "Please, enter a valid option" << std::endl;
        }
    }

    schedule.simulation(10, mode);

    return 0;
}
