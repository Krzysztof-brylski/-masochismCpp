
#ifndef MASOCHISM_SERVER_H
#define MASOCHISM_SERVER_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Router.cpp"
#include "Response.cpp"
#pragma once
#include "../../web/routers.cpp"
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
        char* sendBuffer=new char[4096];
        char* receiveBuffer=new char[4096];
        int lastError=0;
        request* request = new struct request;
        Router* router;
        int processRequest();
        //int sendResponse();
    public:
        Server(char* serverIp,int serverPort,  Router* router);
        ~Server();
        int runServer();
    };
}

#endif //MASOCHISM_SERVER_H
