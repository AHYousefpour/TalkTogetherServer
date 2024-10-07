#include "normalMsgHandler.h"
#include "sendMessage.h"

NormalMsgHandler::NormalMsgHandler(Client client)
: _client(client)
{

}

void NormalMsgHandler::execute()
{
    SendMessage::sendMessageToAll(_client);
}
