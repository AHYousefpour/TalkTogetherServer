#ifndef DISCONNECT_MSG_HANDLER_H
#define DISCONNECT_MSG_HANDLER_H

#include "imessageHandler.h"
#include "client.h"

class DisconnectMsgHandler : public IMessageHandler
{
public:
    DisconnectMsgHandler(Client client);
    void execute() override;

private:
    Client _client;
};

#endif
