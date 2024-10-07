#ifndef NEW_CONNECTION_MSG_HANDLER_H
#define NEW_CONNECTION_MSG_HANDLER_H

#include "imessageHandler.h"
#include "client.h"

class NewConnectionMsgHandler : public IMessageHandler
{
public:
    NewConnectionMsgHandler(Client client);
    void execute() override;

private:
    void sendWelcomeMessage();
    void sendMessageToAll();

    Client _client;
};

#endif