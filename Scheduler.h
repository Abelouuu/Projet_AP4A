


#ifndef AP4ATP1_SCHEDULER_H
#define AP4ATP1_SCHEDULER_H

#include "Sensor.h"
#include <vector>



class Scheduler {
private:
    std::vector<Sensor*> sensors{};
    int waiting_time;
public:
    Scheduler(); //Constructeur par défaut
    Scheduler(int waiting_time); //Constructeur avec paramètre
    Scheduler( const Scheduler &scheduler); //Constructeur par recopie
    ~Scheduler(); //Destructeur
    Scheduler &operator=(const Scheduler &schedule); //Surcharge de l'opérateur =

    int get_waiting_time() const; //Getter
    void set_waiting_time(int waiting_time); //Setter

    void simulation(int nb_cycles) const;
    void add_sensor(Sensor *sensor);
};


#endif //AP4ATP1_SCHEDULER_H