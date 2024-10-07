#include "messageFactory.h"
#include "imessageHandler.h"
#include "messageType.h"
#include "newConnectionMsgHandler.h"
#include "disconnectMsgHandler.h"
#include "normalMsgHandler.h"
#include "statusMsgHandler.h"
#include <string>


MessageFactory::MessageFactory(Client client)
: _client(client)
{

}

IMessageHandler* MessageFactory::creator()
{
    MessageType msgType = (MessageType)getTypeOfMessage();
    IMessageHandler* msgHandler;

    switch (msgType)
    {
        case NewConnection:
        {
            msgHandler = new NewConnectionMsgHandler(_client);
        }break;
        case Message:
        {
            msgHandler = new NormalMsgHandler(_client);
        }break;
        case Status:
        {
            msgHandler = new StatusMsgHandler(_client);
        }break;   
        default: // disconnect
        {
            msgHandler = new DisconnectMsgHandler(_client);
        }break;
    }

    return msgHandler;
}

int MessageFactory::getTypeOfMessage()
{
    std::string message = _client.msg;
    int pos = message.find_last_of("\"type: \"");

    return std::atoi(&message[pos + 1]);
}