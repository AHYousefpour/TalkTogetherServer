#include "manageClients.h"
#include "client.h" 


map<int, Client> ManageClients::_clients = {};
nfds_t ManageClients::_currentSizeOfClients = 0;

void ManageClients::addClient(Client client)
{
    _clients.insert(pair<int, Client>(client.socket, client));
    _currentSizeOfClients++;
}

void ManageClients::removeClient(Client client)
{    
    //free(_clients[ipAddress].msg);

    _clients.erase(client.socket);
    _currentSizeOfClients--;
}

Client ManageClients::getClient(const int socket)
{
    return _clients[socket];
}

string ManageClients::getIPAddressOfClient(Client client)
{
    string ipAddress = inet_ntoa(((struct sockaddr_in*)&client.address)->sin_addr);

    return ipAddress;
}

Client* ManageClients::getClientWithIndex(const int index)
{
    Client* client = nullptr;
    map<int, Client>::iterator item;
    int i = 0;

    for(item = _clients.begin(); item != _clients.end(); item++)
    {
        if(i == index)
        {
            client = &item->second;
            break;
        }   
        i++;
    }

    return client;
}

nfds_t ManageClients::getCurrentSizeOfClients()
{
    return _currentSizeOfClients;
}