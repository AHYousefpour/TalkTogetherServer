#ifndef NEW_CONNECTION_HANDLER_H
#define NEW_CONNECTION_HANDLER_H

class NewConnectionHandler
{
public:    
    NewConnectionHandler(NewConnectionHandler&) = delete;
    NewConnectionHandler(int serverSocket);

    int execute();        
    
private:
    bool acceptClient(struct Client& client);

    int _serverSocket;
};

#endif
