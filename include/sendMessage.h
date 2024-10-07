#ifndef SEND_MESSAGE_H
#define SEND_MESSAGE_H

class SendMessage
{
public:
    SendMessage() = delete;
    SendMessage(SendMessage&) = delete;
    void operator=(const SendMessage&) = delete;

    
    static void sendMessageToAll(struct Client fromClient);
    static void sendWelcomeMessage(struct Client client);

private:
    static void sendMessageToClient(struct Client fromClient, struct Client client);
    static bool isItSelf(struct Client client1, struct Client client2);
};

#endif