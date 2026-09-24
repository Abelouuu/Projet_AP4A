#include <iostream>
#include <filesystem>
#include "Server.h"
int main() {
    Server serveur1 = Server();
    Server::consoleWrite("Temperature_Logs.csv");


    std::cout << "--- Demarrage de la simulation ---" << std::endl;

    // 1. Création du serveur (utilise le constructeur par défaut)
    Server monServeur;

    // 2. Test de la fonction fileWrite avec des fausses données de capteurs
    std::cout << "Ecriture des donnees des capteurs dans les logs..." << std::endl;

    // Simulation d'un capteur de Température (envoie 3 mesures)
    Server::fileWrite("Temperature", "22.5");
    Server::fileWrite("Temperature", "23.1");
    Server::fileWrite("Temperature", "22.8");

    // Simulation d'un capteur d'Humidité (envoie 2 mesures)
    Server::fileWrite("Humidity", "45");
    Server::fileWrite("Humidity", "50");

    // 3. Test de la forme de Coplien (Optionnel mais permet de vérifier que ça ne plante pas)
    Server serveurCopie = monServeur; // Appelle le constructeur de copie
    Server serveurAffectation;
    serveurAffectation = monServeur;  // Appelle l'opérateur d'affectation

    std::cout << "Les tests sont termines. Verifiez les fichiers generes !" << std::endl;
    std::cout << "--- Fin de la simulation ---" << std::endl;

    return 0;
}