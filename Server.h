#ifndef AP4ATP1_SERVER_H
#define AP4ATP1_SERVER_H
#include <map>
#include <string>
#include <vector>

class Server {
    private:
        std::string name;
        std::map<std::string, std::vector<float>> measurements;

    public:
        Server();
        Server(const Server& server);
        ~Server();
        Server &operator=(const Server& serveur);

        // Retrait des static et adaptation des paramètres
        void consoleWrite();
        void fileWrite(const std::string& sensorType, float data);
        void receive(const float measure,const std::string type);
};

#endif //AP4ATP1_SERVER_H