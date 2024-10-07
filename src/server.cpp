#include "server.h"
#include <iostream>
#include <sys/ioctl.h>
#include <sys/socket.h> // for use socket(), bind(), listen(), accept()
#include <arpa/inet.h> // for use inet_addr()
#include "session.h"
using namespace std;

Server* Server::_server = nullptr;

Server::Server(const std::string ipAddress, const int port)
: _ipAddress(ipAddress), _port(port)
{

}

Server::~Server()
{
    delete _session;
    shutdown(_serverSocket, SHUT_RD);
    delete _server;
}

void Server::run()
{
    initialize();
    bindServer();

    std::cout << "Server is runing...\nWaiting for clients..." << std::endl;

    listening(); 
    _session = new Session(_serverSocket);
    _session->handleIncomming();
}

Server* Server::getInstance(const std::string ipAddress, const int port)
{
    if(_server == nullptr)
        if(ipAddress.length() > 0)
            _server = new Server(ipAddress, port);
        else
            std::cerr << "IP Address is invalid!" << std::endl;
    return _server;
}


void Server::initialize()
{
    createSocket();

    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_port = htons(_port);
    _serverAddress.sin_addr.s_addr = inet_addr(_ipAddress.c_str());

}

void Server::createSocket()
{
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(_serverSocket == -1)
    {
        cerr << "Error Invalid Socket!" << endl;
    }
    
    if(ioctl(_serverSocket, FIONBIO) < 0)
    {
        cerr << "Error None block Socket!" << endl;
    }
}

void Server::bindServer()
{
    int result = bind(_serverSocket, (struct sockaddr*)&_serverAddress, sizeof(_serverAddress));
    if(result < 0)
    {
        cerr << "Error Bind Server!" << errno << endl;
        exit(-1);
    }
}

void Server::listening()
{
    listen(_serverSocket, MAXCLIENT);
}   
