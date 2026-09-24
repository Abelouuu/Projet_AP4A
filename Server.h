//
// Created by Myotte-Duquet on 14/09/2026.
//

#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H
#include <string>
class Server {
        std::string name;
    public:
        Server();
        Server(const Server& server);
        ~Server();
        Server &operator=(const Server& serveur);

        static void consoleWrite(const std::string &nomFichier);
        static void fileWrite(const std::string& sensorType, const std::string& data);
};



#endif //AP4ATP1_SERVER_H