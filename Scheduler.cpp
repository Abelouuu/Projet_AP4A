#include "Scheduler.h"
#include <iostream>
#include <thread>
#include <chrono>


Scheduler::Scheduler(): waiting_time(1000) {
    std::cout << "Un schedule vient d'etre initialisé" << std::endl;

}
Scheduler::Scheduler(int waiting_time): waiting_time(waiting_time) {
    std::cout << "Un schedule vient d'etre initialisé" << std::endl;
}
Scheduler::Scheduler(const Scheduler &scheduler) {
        for (Sensor* sensor : scheduler.sensors) {
            if (sensor != nullptr) { //Si le sensor n'est pas un pointeur nul
                this->sensors.push_back(sensor->clone()); //On ajoute à la liste de capteurs chaque capteur avec une nouvelle adresse
            }
        }
        this->waiting_time = scheduler.waiting_time;
    std::cout << "Un schedule vient d'etre copié" << std::endl;

}


Scheduler::~Scheduler() {
    for (Sensor* sensor : this->sensors) {
        delete sensor; //Libère la mémoire allouée dynamiquement de chaque capteur
    }
    sensors.clear(); //Vide le tableau des pointeurs
    std::cout << "Un schedule vient d'etre supprimé" << std::endl;
}


Scheduler &Scheduler::operator=(const Scheduler &schedule) {
    if (this != &schedule) { //On vérifie que les deux Schedulers ne soient pas les mêmes (protection anti auto-affectation)
        for (Sensor* sensor : this->sensors) {
            delete sensor; // On libère la mémoire allouée dynamiquement de chaque sensors
        }
        this->sensors.clear(); // On vide le tableau des pointeurs
        for (Sensor* sensor: schedule.sensors) {
            if (sensor != nullptr) {
                this->sensors.push_back(sensor->clone()); //On copie les sensors dans le bon scheduler avec de nouvelle allocations (Copie profonde)
            }
        }
        this->waiting_time = schedule.waiting_time;
    }

    return *this; //On renvoie la référence du scheduler qui vient d'être rempli
}

int Scheduler::get_waiting_time() const{
    std::cout << "Le temps d'attente est de " << this->waiting_time << std::endl;
    return this->waiting_time;
}

void Scheduler::set_waiting_time(int waiting_time) {
    this->waiting_time = waiting_time;
}


void Scheduler::add_sensor(Sensor *sensor) {
    if (sensor != nullptr) { //On vérifie que sensor ne soit pas un pointeur nul
        this->sensors.push_back(sensor); //On ajoute l'adresse du sensor à la liste de capteurs de l'objet courant
    }
}

void Scheduler::simulation(int nb_cycles) const {
    int mode = -1;
    while (mode != 1 && mode != 0) {
        std::cout << "Mode d'affichage Console(0) ou File(1): " << std::endl;
        std::cin >> mode;
        if (mode != 1 && mode != 0) {
            std::cout << "Please, enter a valid option" << std::endl;
        }
    }
    std::cout << "--Début de la simulation (" << nb_cycles << " cycles)--" << std::endl;
    while (nb_cycles > 0){
        std::cout <<"--" << nb_cycles << " Restant(s)--" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(this->waiting_time));
        for (Sensor* sensor : this->sensors) {
            if (sensor != nullptr) {
                sensor->update(mode);
            }
        }
        if (mode == 0) {
            for ( Server* server : this->servers) {
                server->consoleWrite();
            }
        }
        nb_cycles -= 1;
    }

}


void Scheduler::add_server(Server* server) {
    if ( server != nullptr) {
        this->servers.push_back(server);
    }
}