#include "Scheduler.h"
#include <iostream>

Scheduler::Scheduler() {
    std::cout << "Un schedule vient d'etre initialisé" << std::endl;
}

Scheduler::Scheduler(const Scheduler &scheduler) {
    std::cout << "Un schedule vient d'etre copié" << std::endl;
}


Scheduler::~Scheduler() {
    std::cout << "Un schedule vient d'etre supprimé" << std::endl;
}


Scheduler &Scheduler::operator=(const Scheduler &schedule) {
    if (this != &schedule) {

    }
    return *this;
}
