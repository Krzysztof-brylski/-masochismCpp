//
// Created by Krzysztof on 24.01.2023.
//
#include "Response.h"
#include <map>
#include <functional>
#pragma once
#include <iostream>

responseContainer* error404(){
    return Response::staticHtml("httpError/404.html");
}
responseContainer* error415(){
    return Response::staticHtml("httpError/415.html");
}
map <int, function<responseContainer*()>> configMap;
void config(){
    //default error
    configMap.insert({000, bind(error404)});
    //
    configMap.insert({404, bind(error404)});
    configMap.insert({415, bind(error415)});
}

responseContainer* abort(int errorCode){
    config();
    auto result =configMap.find(errorCode);
    if(result != configMap.end()){
        return result->second();
    }
    return configMap.find(000)->second();
}

