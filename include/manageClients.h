#ifndef MANAGE_CLIENTS_H
#define MANAGE_CLIENTS_H

#include <map>
#include <string>
#include <arpa/inet.h> // for use inet_ntoa()
#include <poll.h> // nfds_t

using namespace std;

class ManageClients
{
public:
    ManageClients() = delete;
    ManageClients(ManageClients&) = delete;
    void operator=(const ManageClients&) = delete;

    static void addClient(struct Client client);
    static void removeClient(struct Client client);
    static struct Client getClient(const int socket);
    static string getIPAddressOfClient(struct Client client);
    static struct Client* getClientWithIndex(const int index);
    static nfds_t getCurrentSizeOfClients();

private:
    static map<int, struct Client> _clients;
    static nfds_t _currentSizeOfClients;
};

#endif