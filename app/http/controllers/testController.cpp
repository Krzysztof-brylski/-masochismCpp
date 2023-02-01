//
// Created by Krzysztof on 19.01.2023.
//
#pragma once
#include "../../../engine/Server/Response.h"
#include "../../../engine/Server/Server.h"


class TestController{
public:
    static responseContainer* index(struct request* Request){
        if(Request->Get["test"]=="test"){
            return  Response::staticHtml("test.html","200");
        }
        return  Response::staticHtml("index.html","200");
    }
    static responseContainer* about(struct request* Request){
        return Response::staticHtml("aboutUs.html","200");
    }
    static responseContainer* test(struct request* Request){
        return Response::staticHtml("aboutUs.html","200");
    }
};