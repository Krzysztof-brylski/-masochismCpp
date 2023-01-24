//
// Created by Krzysztof on 17.01.2023.
//
#pragma once
#include "Router.h"

void Router::Get(string route, function<responseContainer*()> callback) {
    this->Route.insert({make_pair("GET",route), bind(callback)});
}
responseContainer* Router::findRoute(methodeAndRoute methodeAndRoute) {
    auto  result=this->Route.find(make_pair(methodeAndRoute.methode,methodeAndRoute.route));
    if(result != this->Route.end()){
        return result->second();
    }
    return abort(404);
}
Router::~Router() {
    this->Route.clear();
}
Router *router = new Router();

