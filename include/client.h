#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <sys/poll.h> // for use struct pollfd.

#define BUFFER_SIZE 1024 * 2

struct Client
{
    sockaddr address;
    int socket;
    socklen_t socketLen;
    char* msg;
};

#endif