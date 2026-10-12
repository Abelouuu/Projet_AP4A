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
    this->measurements = server.measurements;
}

Server &Server::operator=(const Server &server) {
    if (this != &server) {
        this->name = server.name;
        this->measurements = server.measurements;
    }
    return *this;
}

Server::~Server() {
    std::cout << "Destruction de l'instance Server" <<std::endl;
}

void Server::consoleWrite() {
    std::cout<< "\n[HISTORIQUE DES CAPTEURS]"<<std::endl;
    for (const auto& pair : this->measurements) {
        std::cout << "Capteur " << pair.first << " : ";
        for (std::string val : pair.second) {
            std::cout << val << "  ";
        }
        std::cout << std::endl;
    }
}

void Server::fileWrite(const std::string& sensorType, std::string data) {
    std::string Filename = sensorType + "_Logs.csv";
    std::ofstream LogFile;
    LogFile.open(Filename, std::ios::app);

    if (LogFile.is_open()) {
        LogFile << data << ";" << std::endl;
        LogFile.close();
    }
}

void Server::receive(const std::string measure, const std::string sensorType, int mode) {
    if(this->measurements.find(sensorType) == this->measurements.end()) {
        std::vector<std::string> newList;
        newList.push_back(measure);
        measurements.insert({sensorType, newList});
    } else {
        measurements[sensorType].push_back(measure);
    }
    if (mode == 1) {
        this->fileWrite(sensorType, measure);
    }
}