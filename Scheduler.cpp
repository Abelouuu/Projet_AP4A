#include "Scheduler.h"
#include <iostream>
#include <thread>
#include <chrono>


Scheduler::Scheduler(): waiting_time(1000) {
    std::cout << "Un schedule vient d'etre initialisé" << std::endl;
}
Scheduler::Scheduler(int delay_ms): waiting_time(delay_ms) {
    std::cout << "Un schedule vient d'etre initialisé" << std::endl;
}
Scheduler::Scheduler(const Scheduler &scheduler): waiting_time(scheduler.waiting_time) {
    for (Sensor* sensor : scheduler.sensors) {
        this->sensors.push_back(sensor); // Copie simple du pointeur
    }
    for (Server* server : scheduler.servers) {
        this->servers.push_back(server); // Copie simple du pointeur
    }
}


Scheduler::~Scheduler() {
    sensors.clear();
    servers.clear();
    std::cout << "Un schedule vient d'etre supprimé" << std::endl;
}


Scheduler &Scheduler::operator=(const Scheduler &scheduler) {
    if (this != &scheduler) {
        this->sensors.clear();
        this->servers.clear();

        for (Sensor* sensor: scheduler.sensors) {
            this->sensors.push_back(sensor);
        }
        for (Server* server: scheduler.servers) {
            this->servers.push_back(server);
        }
        this->waiting_time = scheduler.waiting_time;
    }
    return *this;
}

int Scheduler::get_waiting_time() const{
    std::cout << "Le temps d'attente est de " << this->waiting_time << std::endl;
    return this->waiting_time;
}

void Scheduler::set_waiting_time(int delay_ms) {
    this->waiting_time = delay_ms;
}


void Scheduler::add_sensor(Sensor *sensor) {
    if (sensor != nullptr) { //On vérifie que sensor ne soit pas un pointeur nul
        this->sensors.push_back(sensor); //On ajoute l'adresse du sensor à la liste de capteurs de l'objet courant
    }
}

void Scheduler::simulation(int nb_cycles, int mode) const {
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