#include "sendMessage.h"
#include "manageClients.h"
#include "client.h"
#include <string.h>

void SendMessage::sendMessageToAll(Client fromClient)
{
    int currentSizeOfClients = ManageClients::getCurrentSizeOfClients();

    for(int index = 0; index < currentSizeOfClients; index++)
    {
        Client* client = ManageClients::getClientWithIndex(index);
        
        if(!isItSelf(fromClient, *client))
        {
            sendMessageToClient(fromClient, *client);
        }
    }
}

bool SendMessage::isItSelf(Client client1, Client client2)
{
    return (client1.socket == client2.socket) ? true : false;
}

void SendMessage::sendMessageToClient(Client fromClient, Client client)
{    
    // need to add send size.
    int size = strlen(fromClient.msg);
    std::string temp = to_string(size);
    const char* len = temp.c_str();
    send(client.socket, len, sizeof(char*), 0);

    int result = send(client.socket, fromClient.msg, sizeof(fromClient.msg), 0);
}

void SendMessage::sendWelcomeMessage(Client client)
{
    std::string msg = "{\n\t\"type\": 4,\n\t\"message\": \"Welcome to the TalkTogether Server.\"\n}\n";

    send(client.socket, msg.c_str(), msg.length(), 0);
}