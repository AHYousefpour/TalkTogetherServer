#ifndef SESSION_H
#define SESSION_h

#include <sys/poll.h>
#include "client.h"

#define MAXCLIENT 1024

class Session 
{
public:
    Session(int serverSocket);
    void handleIncomming();
    
private:    
    void polling();
    bool isNewConnection(const int index);
    void addClientToPollRequests(const int clientSocket);
    void readAllMessages();
    void sendMessage(Client client);

    int _serverSocket;
    static pollfd _pollRequests[MAXCLIENT];
    static int _currentSizeOfRequests;
};

#endif