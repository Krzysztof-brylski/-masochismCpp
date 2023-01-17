
#ifndef MASOCHISM_SERVER_H
#define MASOCHISM_SERVER_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct request{
    string  methode="";
    string route="";
    string protocol="";
    string host="";
};
using namespace std;
namespace MasochismServer{
    class Server {
    private:
        WSADATA wsaData;
        sockaddr_in service;
        SOCKET mainSocket,acceptSocket;
        char* sendBuffer;
        char* receiveBuffer;
        int lastError;
        request* request = new struct request;

        int processRequest();
        int sendResponse();
    public:
        Server(char* serverIp,int serverPort);
        int runServer();
    };
}

#endif //MASOCHISM_SERVER_H
