#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H

#include "Data/Data.h"
#include <map>
#include <string>
#include <vector>

class Server {
private:
    std::string name;
    // Dictionnaire associant chaque type de capteur à l'historique de ses mesures (Data*)
    std::map<std::string, std::vector<Data*>> measurements;

public:
    // Forme canonique de Coplien
    Server();
    Server(const Server& server);
    ~Server();
    Server &operator=(const Server& serveur);

    // Services d'affichage console, d'export CSV et de réception des mesures
    void consoleWrite();
    void fileWrite(const std::string& sensorType, Data* data);
    void receive(Data* measure, const std::string& type, int mode);
};

#endif //AP4ATP1_SERVER_H