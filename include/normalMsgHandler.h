#ifndef NORMAL_MSG_HANDLER_H
#define NORMAL_MSG_HANDLER_H

#include "imessageHandler.h"
#include "client.h"

class NormalMsgHandler : public IMessageHandler
{
public:
    NormalMsgHandler(Client client);
    void execute() override;

private:
    Client _client;
};

#endif