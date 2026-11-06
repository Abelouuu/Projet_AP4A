#ifndef AP4ATP1_SCHEDULER_H
#define AP4ATP1_SCHEDULER_H

#include "Sensor.h"
#include <vector>

class Scheduler {
private:
    // Conteneurs de pointeurs pour manipuler les capteurs de façon polymorphe (agrégation)
    std::vector<Sensor*> sensors{};
    std::vector<Server*> servers{};
    int waiting_time; // Temps d'attente en millisecondes entre deux cycles

public:
    // Forme canonique de Coplien
    Scheduler();
    Scheduler(int delay_ms);
    Scheduler(const Scheduler &scheduler);
    ~Scheduler();
    Scheduler &operator=(const Scheduler &scheduler);

    int get_waiting_time() const; // Getter
    void set_waiting_time(int delay_ms); // Setter

    void add_sensor(Sensor *sensor);
    void add_server(Server *server);
    void simulation(int nb_cycles, int mode) const;
};

#endif //AP4ATP1_SCHEDULER_H