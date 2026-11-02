#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H

#include "Data/Data.h"
#include <map>
#include <string>
#include <vector>

class Server {
    private:
        std::string name;
        std::map<std::string, std::vector<Data*>> measurements;

    public:
        Server();
        Server(const Server& server);
        ~Server();
        Server &operator=(const Server& serveur);

        // Retrait des static et adaptation des paramètres
        void consoleWrite();
        void fileWrite(const std::string& sensorType, Data* data);
        void receive(Data* measure,const std::string& type, int mode);
};

#endif //AP4ATP1_SERVER_H