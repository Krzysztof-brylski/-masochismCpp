//
// Created by Krzysztof on 17.01.2023.
//

#include "Router.h"

void Router::Get(std::string route, std::string path) {
    this->GetRoute.insert({route, path});
}
string Router::executeRoute(string route) {
    auto  result=this->GetRoute.find(route);
    string line="",file="";
    fstream fstream1;
    fstream1.open("../resources/html/"+result->second);
    while( getline(fstream1,line)){
        file+=(line+"\n");
    }
    fstream1.close();
    cout<<file<<endl;
    return file;
}
Router::~Router() {
    this->GetRoute.clear();
}

