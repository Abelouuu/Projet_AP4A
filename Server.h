#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H
#include <map>
#include <string>
#include <vector>

class Server {
    private:
        std::string name;
        std::map<std::string, std::vector<std::string>> measurements;

    public:
        Server();
        Server(const Server& server);
        ~Server();
        Server &operator=(const Server& serveur);

        // Retrait des static et adaptation des paramètres
        void consoleWrite();
        void fileWrite(const std::string& sensorType, std::string data);
        void receive(const std::string measure,const std::string type, int mode);
};

#endif //AP4ATP1_SERVER_H