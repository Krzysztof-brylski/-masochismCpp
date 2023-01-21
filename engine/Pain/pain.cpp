#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "Assets/PainFunctions.cpp"
#include <string.h>
using namespace std;
class Pain{
protected:
    fstream file;

    vector <string> fileLines;
    vector <commandRange> commandRangeStack;
    stack <commandBlock> commandStack;
private:
    void detectCommand(string line,int lineNo){
        commandRange range;
        range.start=line.find("@");
        range.end=line.find("@",range.start+1);
        range.lineNo=lineNo;
        if(range.start != -1 and range.end != -1){
            commandRangeStack.push_back(range);
        }
    }
    void runFileAnalysis(){
        int lineNo=0;
        string line;
        while(getline(this->file,line)){
            this->detectCommand(line,lineNo);
            this->fileLines.push_back(line);
            lineNo++;
        }
        this->file.close();
    }
    void processCommandRangeStack(commandRange commandStartRange,commandRange commandEndRange){
        string line;
        line=this->fileLines[commandStartRange.lineNo];
        int range=commandStartRange.end-commandStartRange.start;

        commandBlock commandBlock;
        commandBlock.start=commandStartRange.lineNo;
        commandBlock.end=commandEndRange.lineNo;
        commandBlock.contentStart=commandBlock.start+1;
        commandBlock.contentEnd=commandBlock.end-1;
        commandBlock.commandName=line.substr(commandStartRange.start,range);

        this->commandStack.push(commandBlock);
    }
    void processCommandRangeStack(){
        int size=this->commandRangeStack.size();
        for(int i =0;i<size/2;i++){
            commandRange commandStartRange = this->commandRangeStack.front();
            commandRange commandEndRange = this->commandRangeStack.back();

            processCommandRangeStack(commandStartRange,commandEndRange);

            this->commandRangeStack.pop_back();
            this->commandRangeStack.erase(commandRangeStack.begin());
        }
    }
    int extractParameters(string name){
        int first=name.find("(");
        return int(name[first+1]-'0');
    }
    void executeCommandBlockStack(){
        int size=this->commandStack.size();
        PainFunctions func;
        for(int i=0;i<size;i++){
            commandBlock commandBlock=this->commandStack.top();
            string name=commandBlock.commandName;
            cout<<this->extractParameters(name)<<endl;
            func.painFor(this->fileLines,this->extractParameters(name),commandBlock);
            cout<<"commandBlock:"<<name<<" range:"<<commandBlock.start<<" / "
            <<commandBlock.end<<" content-range:"<<commandBlock.contentStart<<" / "<<commandBlock.contentEnd<<endl;
            commandStack.pop();

        }

    }
    void cleanUp(){
        for(int i=0;i<this->fileLines.size();i++){
            int find=this->fileLines[i].find("@");
            if(find != string::npos){
                this->fileLines.erase((this->fileLines.begin()+i));
            }
        }
    }
    string implode(){
        string result;
        for(int i=0;i<this->fileLines.size();i++){
            result+=(this->fileLines[i]+"\r\n");
        }

        return result;
    }
public:

    Pain(string path){
        this->file.open(path);
    }
    ~Pain(){
        this->fileLines.clear();
        this->commandRangeStack.clear();
    }
    string run(){
        this->runFileAnalysis();
        this->processCommandRangeStack();
        this->executeCommandBlockStack();
        this->cleanUp();

//        cout<<"____________________"<<endl;
//        for(int i=0;i<this->fileLines.size();i++){
//            cout<<i<<". "<<this->fileLines[i]<<endl;
//        }
        return this->implode();
    }

};