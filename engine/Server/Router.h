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
#include "serverDataStructures.h"
#pragma once
using namespace std;
using namespace std::placeholders;
class Router {
private:
    map <string, map <string,function<responseContainer*(request*)> > > Route;

    //map <string,string> GetRoute;
public:

    responseContainer* findRoute(request* Request);

    void Get(string route, function<responseContainer*(request*)> callback);
    void Post(string route, function<responseContainer*(request*)> callback);
    ~Router();
};


#endif //MASOCHISM_ROUTER_H
