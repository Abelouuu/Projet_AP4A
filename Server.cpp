#include "Server.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Server::Server() {
    std::cout << "Un serveur vient d'etre initialise" << std::endl;
    this->name = "ServeurSolide";
}

// Constructeur par recopie : réalise une copie profonde (deep copy) via clone()
// pour que chaque serveur possède ses propres allocations mémoire
Server::Server(const Server &server) {
    std::cout << "Copie en cours" << std::endl;
    this->name = server.name;
    for (const auto& pair : server.measurements) {
        for (Data* d : pair.second) {
            this->measurements[pair.first].push_back(d->clone());
        }
    }
}

Server &Server::operator=(const Server &server) {
    if (this != &server) {
        this->name = server.name;
        this->measurements = server.measurements;
        // Nettoyage de l'ancienne mémoire avant de cloner les nouvelles données
        for (auto& pair : this->measurements) {
            for (Data* d : pair.second) { delete d; }
        }
        this->measurements.clear();
        for (const auto& pair : server.measurements) {
            for (Data* d : pair.second) {
                this->measurements[pair.first].push_back(d->clone());
            }
        }
    }
    return *this;
}

// Destructeur : libère toutes les mesures clonées dynamiquement dans la map
Server::~Server() {
    for (auto& pair : this->measurements) {
        for (Data* d : pair.second) {
            delete d;
        }
    }
    std::cout << "Destruction de l'instance Server" << std::endl;
}

void Server::receive(Data* measure, const std::string& type, int mode) {
    // Le serveur stocke un CLONE de la donnée pour être indépendant du cycle de vie du capteur
    this->measurements[type].push_back(measure->clone());

    // Vérification des seuils critiques à chaque réception
    measure->checkAlert(type);

    // En mode fichier (1), on enregistre la mesure en temps réel dans le CSV correspondant
    if (mode == 1) {
        this->fileWrite(type, measure);
    }
}

void Server::consoleWrite() {
    std::cout << "\n[HISTORIQUE DES CAPTEURS]" << std::endl;
    // Parcours de chaque catégorie de capteur et de son vecteur de mesures
    for (const auto& pair : this->measurements) {
        std::cout << "Capteur " << pair.first << " : ";
        for (Data* val : pair.second) {
            std::time_t t = std::time(nullptr);
            std::tm* tm = std::localtime(&t);
            // Affichage horodaté grâce à std::put_time et appel polymorphe à toString()
            std::cout << std::put_time(tm, "%d/%m/%Y %H:%M:%S: ") << val->toString() << ",  ";
        }
        std::cout << std::endl;
    }
}

void Server::fileWrite(const std::string& sensorType, Data* data) {
    // Création d'un fichier de log dédié par type de capteur
    std::string filename = sensorType + "_Logs.csv";
    std::ofstream LogFile;
    // Ouverture en mode std::ios::app (append) pour ajouter à la suite sans écraser l'historique
    LogFile.open(filename, std::ios::app);

    if (LogFile.is_open()) {
        std::time_t t = std::time(nullptr);
        std::tm* tm = std::localtime(&t);
        // Formatage avec point-virgule pour faciliter l'ouverture directe dans Excel
        LogFile << std::put_time(tm, "%d/%m/%Y %H:%M:%S: ") << data->toString() << ";" << std::endl;
        LogFile.close();
    }
}