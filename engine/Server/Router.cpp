//
// Created by Krzysztof on 17.01.2023.
//
#pragma once
#include "Router.h"

void Router::Get(string route, function<responseContainer*()> callback) {
    this->Route[route].insert({"GET",bind(callback)});
    //this->Route.insert({route,this->Route.insert[route].insert()}});
}
void Router::Post(string route, function<responseContainer*()> callback) {
    this->Route[route].insert({"POST",bind(callback)});
    //this->Route.insert({route,this->Route.insert[route].insert()}});
}
responseContainer* Router::findRoute(methodeAndRoute methodeAndRoute) {
    auto  result=this->Route.find(methodeAndRoute.route);
    if(result != this->Route.end()){
        auto  result=this->Route[methodeAndRoute.route].find(methodeAndRoute.methode);
        if(result != this->Route[methodeAndRoute.route].end()){
            return result->second();
        }
        return abort(415);
    }
    return abort(404);
}
Router::~Router() {
    this->Route.clear();
}
Router *router = new Router();

