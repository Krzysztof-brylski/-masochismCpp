//
// Created by Krzysztof on 19.01.2023.
//
#pragma once
#include "../../../engine/Server/Response.h"
class TestController{
public:
    static responseContainer* index(map<string,string> params){
        cout<<params["test1"]<<endl;
        return  Response::staticHtml("index.html","200");
    }
    static responseContainer* about(map<string,string> params){
        return Response::staticHtml("aboutUs.html","200");
    }
    static responseContainer* test(map<string,string> params){
        return Response::staticHtml("test.html","200");
    }
};