#include "newConnectionHandler.h"
#include <sys/socket.h>
#include "manageClients.h"
#include "sendMessage.h"
#include "client.h"

#include <iostream>

NewConnectionHandler::NewConnectionHandler(int serverSocket)
: _serverSocket(serverSocket)
{

}

int NewConnectionHandler::execute()
{
    Client client;

    if(acceptClient(client))
    {
        std::cout << "This IP Address " << ManageClients::getIPAddressOfClient(client) << " has connected to the server." << std::endl;

        ManageClients::addClient(client);
    }

    return client.socket;
}

bool NewConnectionHandler::acceptClient(Client& client)
{
    client.socket = accept(_serverSocket, &client.address, &client.socketLen);

    if(client.socket == -1) // is invalid socket?
        return false;

    return true;
}
