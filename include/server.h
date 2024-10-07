#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <netinet/in.h> 

class Server
{
public:
    Server(Server &) = delete;
    void operator=(const Server&) = delete;

    void run();
    static Server* getInstance(const std::string ipAddress = "127.0.0.1", const int port = 8080);

private:
    Server(const std::string ipAddress, const int port);
    ~Server();    
    void initialize();
    void createSocket();
    void bindServer();
    void listening();    
        
    static Server* _server;
    std::string _ipAddress;
    int _serverSocket;
    int _port;
    sockaddr_in _serverAddress;
    class Session* _session;
};

#endif