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
#pragma once
using namespace std;
class Router {
private:
    map <string, function<responseContainer()>> GetRoute;

    //map <string,string> GetRoute;
public:
    map <string,string>  getRoutes();
    responseContainer findRoute(string route);
    string executeRoute(string route);
    void Get(string route, function<responseContainer()> callback);
    ~Router();
};


#endif //MASOCHISM_ROUTER_H
