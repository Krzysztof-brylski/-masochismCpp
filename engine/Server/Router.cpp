//
// Created by Krzysztof on 17.01.2023.
//
#pragma once
#include "Router.h"

void Router::Get(std::string route, function<responseContainer()> callback) {
    this->GetRoute.insert({route, bind(callback)});
}
responseContainer Router::findRoute(string route) {
    auto  result=this->GetRoute.find(route);

    return  result->second();
}
string Router::executeRoute(string route) {
//    auto  result=this->GetRoute.find(route);
//    string line="",file="";
//    fstream fstream1;
//    fstream1.open("../resources/html/"+result->second);
//    while( getline(fstream1,line)){
//        file+=(line+"\n");
//    }
//    fstream1.close();
//    cout<<file<<endl;
//    return file;
}
Router::~Router() {
    this->GetRoute.clear();
}
Router *router = new Router();

