#include "session.h"
#include "imessageHandler.h"
#include "recvMessage.h"
#include "messageType.h"
#include "manageClients.h"
#include "newConnectionHandler.h"
#include "messageFactory.h"

#include <iostream>
#include <cstring>
using namespace std;

int Session::_currentSizeOfRequests = 1;
pollfd Session::_pollRequests[MAXCLIENT];

Session::Session(int serverSocket)
: _serverSocket(serverSocket)
{
    memset(_pollRequests, 0, sizeof(_pollRequests));

    _pollRequests[0].fd = _serverSocket;
    _pollRequests[0].events = POLLIN;
}

void Session::handleIncomming()
{
    while(true)
    {       
        polling();

        for(int index = 0; index < _currentSizeOfRequests; index++)
        {
            if(_pollRequests[index].revents == 0)
                continue;

            if(isNewConnection(index))
            {
                NewConnectionHandler* newConnection = new NewConnectionHandler(_serverSocket);
    
                int clientSocket = newConnection->execute();
                addClientToPollRequests(clientSocket);
                
                delete newConnection;
            }
            else
            {
                readAllMessages();
            }
        }
    }
}

void Session::polling()
{
    int result = poll(_pollRequests, _currentSizeOfRequests, 10000);

    if(result < 0)
    {
        cerr << "Error on Poll" << endl;
    }

    if(result == 0)
    {
        cout << "Time Out Poll." << endl;
    }
}

bool Session::isNewConnection(const int index)
{
    return (_pollRequests[index].fd == _serverSocket) ? true : false;
}

void Session::addClientToPollRequests(const int clientSocket)
{
    if(clientSocket != -1)
    {
        _pollRequests[_currentSizeOfRequests].fd = clientSocket;
        _pollRequests[_currentSizeOfRequests].events = POLLIN;
        _currentSizeOfRequests++;
    }
}

void Session::readAllMessages()
{
    int index = 0;
    while (true)
    {
        Client* client = ManageClients::getClientWithIndex(index);

        if(client == nullptr)
            break;

        RecvMessage::recvMessageFromClient(client);

        sendMessage(*client);

        index++;
    }
}

void Session::sendMessage(Client client)
{
    MessageFactory* msgFactory = new MessageFactory(client);

    IMessageHandler* msgHandler = msgFactory->creator();
    msgHandler->execute();

    delete msgFactory;
    delete msgHandler;
}
