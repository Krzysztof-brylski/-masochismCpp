#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "engine/pain/pain.cpp"
#include "engine/server/Server.cpp"

using namespace std;

int main() {



   MasochismServer::Server server((char*)"127.0.0.1",7777, router);
   return server.runServer();

   delete router;
//    map <string,string> data;
//    data["test2"]="test";
//    Pain pain("test.pain.html",data);
//    pain.run();
}
