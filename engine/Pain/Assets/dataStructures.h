#pragma once
#include <string.h>
#include <iostream>
struct commandRange{
    int start;
    int end;
    int lineNo;
};
struct insertBlock{
    int lineNo=0;
    int start=0;
    int end=0;
    std::string keyName;
};
struct commandBlock{
    int start=0;
    int end=0;

    int contentStart=0;
    int contentEnd=0;

    std::string commandName;
};