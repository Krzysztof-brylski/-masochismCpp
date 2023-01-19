//
// Created by Krzysztof on 18.01.2023.
//

#ifndef MASOCHISM_RESPONSE_H
#define MASOCHISM_RESPONSE_H
#include <iostream>
#include <fstream>
#pragma once
using namespace std;
struct responseContainer{
    char* content;
    int size;
};
class Response {
private:
    static string readFile(string path);
public:

    static string view(string path,string code);
    static responseContainer staticHtml(string path,string code="200");
    static string json();
};


#endif //MASOCHISM_RESPONSE_H
