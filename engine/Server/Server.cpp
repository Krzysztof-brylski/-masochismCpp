//
// Created by Krzysztof on 17.01.2023.
//

#include "Server.h"


MasochismServer::Server::Server(char* serverIp, int serverPort,Router* router){
    int result = WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
    if( result != NO_ERROR )
        printf( "Initialization error.\n" );

    this->mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if( this->mainSocket == INVALID_SOCKET )
    {
        printf( "Error creating socket: %ld\n", WSAGetLastError() );
        WSACleanup();
        this->lastError=1;
    }

    memset( &this->service, 0, sizeof( this->service ) );
    this->service.sin_family = AF_INET;
    this->service.sin_addr.s_addr = inet_addr( serverIp );
    this->service.sin_port = htons( serverPort );
    this->router=router;
    routers();
}
MasochismServer::Server::~Server(){
    delete[] this->sendBuffer;
    delete[] this->receiveBuffer;
    delete this->router;
    delete router;
    delete this->request;
}
map<string,string> MasochismServer::Server::decodeUrl(string url){
    map <string,string> parameters;
    int pos=url.find("?");
    if(pos == string::npos){
        this->request->route=url;
        return parameters;
    }
    this->request->route=url.substr(0, pos);
    string params = url.substr(pos+1, url.length());
    char* params1= strdup(params.c_str());
    char* param=strtok(params1, "&");

    while(param != nullptr){
        int pos=((string)param).find("=");
        string key=((string)param).substr(0,pos);
        string value=((string)param).substr(pos+1,((string)param).length());
        parameters[key]=value;
        param=strtok(nullptr, "");
    }
    return parameters;
}

int MasochismServer::Server::processRequest() {

    int bytesReceive = recv( this->acceptSocket, this->receiveBuffer, 4096, 0 );
    char* requestHeader=strtok(this->receiveBuffer, "\n");
    char* requestParameters=strtok(requestHeader," ");
    int counter=0;

    while(requestParameters != nullptr){
        switch(counter){
            case 0:
                this->request->methode=requestParameters;
                break;
            case 1:
                this->request->route=requestParameters;
                break;
            case 2:
                this->request->protocol=requestParameters;
                break;
        }
        requestParameters=strtok(nullptr," ");
        counter++;
    }
    this->request->Get = this->decodeUrl(this->request->route);
    this->request->Post ={};
//    cout<<this->request->methode<<endl;
//    cout<<this->request->route<<endl;
//    cout<<this->request->protocol<<endl;
    return 0;
}




int MasochismServer::Server::runServer() {
    if(this->lastError != 0){
        return 1;
    }
    if( bind( this->mainSocket,( SOCKADDR * ) & this->service, sizeof( this->service ) ) == SOCKET_ERROR )
    {
        printf( "bind failed.\n" );
        closesocket( this->mainSocket );
        return 1;
    }
    if( listen( mainSocket, 1 ) == SOCKET_ERROR )
        printf( "Error listening on socket.\n" );

    this->acceptSocket = SOCKET_ERROR;
    printf( "Waiting for a client to connect...\n" );

    while(true)
    {
        this->acceptSocket = accept( this->mainSocket, NULL, NULL );
        this->processRequest();
        auto func=[](int socket,struct request* Request, Router* router){

            responseContainer* responseContainer = router->findRoute(Request);
            send(socket, responseContainer->content, responseContainer->size, 0);
            closesocket(socket);
            delete[] responseContainer->content;
            delete responseContainer;
        };
        thread thread_object(func, this->acceptSocket,this->request,this->router);
        thread_object.join();
        //delete responseContainer;
    }

}
