#include "Server.h"
#include <iostream>
#include <fstream>


Server::Server() {
    std::cout << "Un serveur vient d'etre initialise"<<std::endl;
    this->name = "ServeurSolide";
}

Server::Server(const Server &server) {
    std::cout << "Copie en cours"<<std::endl;
    this->name = server.name;
}

Server &Server::operator=(const Server &other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

Server::~Server() {
    std::cout << "Destruction de l'instance Server" <<std::endl;
}


void Server::consoleWrite(const string& nomFichier) {
    std::ifstream logfile(nomFichier);
    if (logfile.is_open()) {
        string ligne;
        std::cout<< "[LISTE DES LOGS]"<<std::endl;
        while (getline(logfile, ligne)) {
            std::cout << ligne << std::endl;
        }
        logfile.close();
    }
    else {
        std::cout << "Aucun fichier de logs trouve" << std::endl;
    }


}


