//
// Created by Krzysztof on 18.01.2023.
//

#include "Response.h"

string Response::readFile(string path) {
    string line="",file="";
    fstream fstream1;
    fstream1.open("../resources/html/"+path);
    while( getline(fstream1,line)){
        file+=(line+"\n");
    }
    fstream1.close();
    cout<<path<<endl;
    return file;
}

responseContainer Response::staticHtml(string path, string code) {

    responseContainer responseContainer;


    string html = Response::readFile(path);
    cout<<html.length()<<endl;
    int size=html.length()+85;
    char* http_header= new char[size];
    string len="Content-Length: "+to_string(size)+"\r\n";
    memset(http_header,0,size);
    strcat(http_header, "HTTP/1.1 200 OK\r\n");
    strcat(http_header, "Content-type: text/html\r\n");
    strcat(http_header, len.c_str());
    strcat(http_header, "Connection: lose\r\n");
    strcat(http_header, "\r\n");
    strcat(http_header, html.c_str());

    responseContainer.content =http_header;
    responseContainer.size=size;

    return responseContainer;
}