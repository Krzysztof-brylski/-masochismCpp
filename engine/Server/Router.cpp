//
// Created by Krzysztof on 17.01.2023.
//
#pragma once
#include "Router.h"
#include "Server.h"

using namespace std::placeholders;
void Router::Get(string route, function<responseContainer*(request*)> callback) {
    this->Route[route].insert({"GET",bind(callback, _1)});
}
void Router::Post(string route, function<responseContainer*(request*)> callback) {
    this->Route[route].insert({"POST",bind(callback, _1)});
}
responseContainer* Router::findRoute(request* Request) {
    auto  result=this->Route.find( Request->route);
    if(result != this->Route.end()){
        auto  result=this->Route[Request->route].find(Request->methode);
        if(result != this->Route[Request->route].end()){
            return result->second(Request);
        }
        return abort(415);
    }
    return abort(404);
}
Router::~Router() {
    this->Route.clear();
}
Router *router = new Router();

