#include "manageClients.h"
#include "client.h" 


map<string, Client> ManageClients::_clients = {};
nfds_t ManageClients::_currentSizeOfClients = 0;

void ManageClients::addClient(Client client)
{
    string ipAddress = getIPAddressOfClient(client);

    _clients.insert(pair<string, Client>(ipAddress, client));
    _currentSizeOfClients++;
}

void ManageClients::removeClient(Client client)
{
    string ipAddress = getIPAddressOfClient(client);
    
    //free(_clients[ipAddress].msg);

    _clients.erase(ipAddress);
    _currentSizeOfClients--;
}

Client ManageClients::getClient(string ipAddress)
{
    return _clients[ipAddress];
}

string ManageClients::getIPAddressOfClient(Client client)
{
    string ipAddress = inet_ntoa(((struct sockaddr_in*)&client.address)->sin_addr);

    return ipAddress;
}

string ManageClients::getMessageOfClient(string ipAddress)
{
    string msg = _clients[ipAddress].msg;

    return msg;
}

Client* ManageClients::getClientWithIndex(const int index)
{
    Client* client = nullptr;
    map<string, Client>::iterator item;
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