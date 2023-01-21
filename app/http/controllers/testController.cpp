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
        return Response::view("test.pain.html","200");
    }
    //todo fix bug with pain for loop seeing only first digit as loop parameter
};