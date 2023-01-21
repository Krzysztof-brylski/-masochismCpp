//
// Created by Krzysztof on 19.01.2023.
//
#pragma once
#include "../../../engine/Server/Response.h"
class TestController{
public:
    static responseContainer* index(){
        return  Response::staticHtml("index.html","200");
    }
    static responseContainer* about(){
        return Response::staticHtml("aboutUs.html","200");
    }
    static responseContainer* test(){
        return Response::staticHtml("test.html","200");
    }
};