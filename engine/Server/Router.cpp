//
// Created by Krzysztof on 17.01.2023.
//
#pragma once
#include "Router.h"
using namespace std::placeholders;
void Router::Get(string route, function<responseContainer*(map<string,string> params)> callback) {
    this->Route[route].insert({"GET",bind(callback, _1)});
}
void Router::Post(string route, function<responseContainer*(map<string,string> params)> callback) {
    this->Route[route].insert({"POST",bind(callback, _1)});
}
responseContainer* Router::findRoute(methodeAndRoute methodeAndRoute, map<string,string> params) {
    auto  result=this->Route.find(methodeAndRoute.route);
    if(result != this->Route.end()){
        auto  result=this->Route[methodeAndRoute.route].find(methodeAndRoute.methode);
        if(result != this->Route[methodeAndRoute.route].end()){
            return result->second(params);
        }
        return abort(415);
    }
    return abort(404);
}
Router::~Router() {
    this->Route.clear();
}
Router *router = new Router();

