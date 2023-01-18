//
// Created by Krzysztof on 17.01.2023.
//

#ifndef MASOCHISM_ROUTER_H
#define MASOCHISM_ROUTER_H
#include <map>
#include <iostream>
#include <functional>
#include <fstream>
using namespace std;
class Router {
private:
    map <string,string> GetRoute;

    //map <string,string> GetRoute;
public:
    map <string,string>  getRoutes();
    string executeRoute(string route);
    void Get(string route,string path);
    ~Router();
};


#endif //MASOCHISM_ROUTER_H
