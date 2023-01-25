//
// Created by Krzysztof on 17.01.2023.
//

#ifndef MASOCHISM_ROUTER_H
#define MASOCHISM_ROUTER_H
#include <map>
#include <iostream>
#include <functional>
#include <fstream>
#include "Response.h"
#include "httpErrors.cpp"
#pragma once
using namespace std;
struct methodeAndRoute{
    string methode;
    string route;
};

class Router {
private:
    map <string, map <string,function<responseContainer*()>>> Route;

    //map <string,string> GetRoute;
public:

    responseContainer* findRoute(methodeAndRoute methodeAndRoute);

    void Get(string route, function<responseContainer*()> callback);
    void Post(string route, function<responseContainer*()> callback);
    ~Router();
};


#endif //MASOCHISM_ROUTER_H
