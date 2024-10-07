#include "newConnectionMsgHandler.h"
#include "sendMessage.h"
#include <string>

NewConnectionMsgHandler::NewConnectionMsgHandler(Client client)
: _client(client)
{

}

void NewConnectionMsgHandler::execute()
{   
    SendMessage::sendWelcomeMessage(_client);
    SendMessage::sendMessageToAll(_client);
}
