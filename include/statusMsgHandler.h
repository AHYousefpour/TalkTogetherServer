#ifndef STATUS_MSG_HANDLER_H
#define STATUS_MSG_HANDLER_H

#include "imessageHandler.h"
#include "client.h"

class StatusMsgHandler : public IMessageHandler
{
public:
    StatusMsgHandler(Client client);
    void execute() override;

private:
    Client _client;
};

#endif