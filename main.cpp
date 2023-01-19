#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine/pain/pain.cpp"
#include "engine/server/Server.cpp"

using namespace std;

int main() {



   MasochismServer::Server server((char*)"127.0.0.1",6969, router);
   return server.runServer();

   delete router;
}
