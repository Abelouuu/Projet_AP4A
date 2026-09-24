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

Server &Server::operator=(const Server &server) {
    if (this != &server) {
        this->name = server.name;
    }
    return *this;
}

Server::~Server() {
    std::cout << "Destruction de l'instance Server" <<std::endl;
}


void Server::consoleWrite(const std::string& nomFichier) {
    std::ifstream logfile(nomFichier);
    if (logfile.is_open()) {
        std::string ligne;
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

void Server::fileWrite(const std::string& sensorType, const std::string &data) {
    std::string Filename = sensorType + "_Logs.csv";
    std::ofstream LogFile;
    LogFile.open(Filename, std::ios::app);

    if (LogFile.is_open()) {
        LogFile << data << ";" << std::endl;
        LogFile.close();
    }
}

