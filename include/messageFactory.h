#ifndef MESSAGE_FACTORY_H
#define MESSAGE_FACTORY_H

#include "client.h"

class MessageFactory
{
public:
    MessageFactory(MessageFactory&) = delete;
    MessageFactory(Client client);
    class IMessageHandler* creator();

private:
    int getTypeOfMessage();
    Client _client;
};

#endif