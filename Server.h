//
// Created by Myotte-Duquet on 14/09/2026.
//

#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H
#include <string>
using namespace std;

class Server {
        string name;
    public:
        Server();
        Server( const Server& server);
        ~Server();
        Server &operator = (const Server& serveur);

        static void consoleWrite(const string &sensortype);
        void fileWrite();
};



#endif //AP4ATP1_SERVER_H