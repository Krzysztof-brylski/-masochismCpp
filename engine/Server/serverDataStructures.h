#include <map>
#include <iostream>
#pragma once
using namespace std;
struct request{
    string  methode="";
    string route="";
    string protocol="";
    string host="";
    map <string,string> Get={};
    map <string,string> Post={};
};
