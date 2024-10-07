#include <iostream>
#include "server.h"
using namespace std;

int main(int argc, char *argv[]) 
{
    cout << "ipaddress: " << argv[1] << endl << "port: " << atoi(argv[2]) << endl;
    
    Server* server = Server::getInstance(argv[1], atoi(argv[2]));
    server->run();

    return 0;
}
