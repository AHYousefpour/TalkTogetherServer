#ifndef RECV_MESSAGE_H
#define RECV_MESSAGE_H

class RecvMessage
{
public:
    RecvMessage() = delete;
    RecvMessage(RecvMessage&) = delete;
    static void recvMessageFromClient(struct Client* client);

private:
    static int recvSizeOfMessage(struct Client client);
};

#endif