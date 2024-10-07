#include "recvMessage.h"
#include <cstring> // for use strcmp().
#include "client.h"
#include "manageClients.h"
#include "sendMessage.h"

#include <iostream>


void RecvMessage::recvMessageFromClient(Client *client)
{ 
    int size = recvSizeOfMessage(*client);

    if(size != 0)
    {
        std::cout << "len : " << size << std::endl;

        char* buffer = new char[size];

        if(0 < recv(client->socket, buffer, size, MSG_DONTWAIT))
        {
            std::cout << "message:\n" << buffer << std::endl;

            client->msg = new char[size];

            client->msg = buffer;
        }

        //delete buffer;
        std::cout << "msg:\n" << client->msg << std::endl;
        
    }
}

int RecvMessage::recvSizeOfMessage(Client client)
{
    char* len;
    recv(client.socket, len, sizeof(char*), MSG_DONTWAIT);

    return std::atoi(len);
}
