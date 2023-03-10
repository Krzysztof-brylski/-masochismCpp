#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include "Assets/PainFunctions.cpp"
#include <string.h>
using namespace std;
class Pain{
protected:
    fstream file;

    vector <string> fileLines;
    vector <commandRange> commandRangeStack;
    vector <insertBlock> insertBlockStack;
    stack <commandBlock> commandStack;
    map <string,string> data;
private:
    void detectCommand(string line,int lineNo){
        commandRange range;
        range.start=line.find("@");
        range.end=line.find("@",range.start+1);
        range.lineNo=lineNo;
        if(range.start != -1 and range.end != -1){
            this->commandRangeStack.push_back(range);
        }
    }
    void detectInsert(string line,int lineNo){
        insertBlock block;
        block.start=line.find("#");
        block.end=line.find("#",block.start+1);
        if( block.start == std::string::npos or block.end == std::string::npos){
            return;
        }
        block.lineNo=lineNo;
        block.keyName=line.substr(block.start+1,(block.end-block.start)-1);
        cout<<block.keyName<<" "<<endl;
        this->insertBlockStack.push_back(block);
    }
    void runFileAnalysis(){
        int lineNo=0;
        string line;
        while(getline(this->file,line)){
            this->detectCommand(line,lineNo);
            this->detectInsert(line,lineNo);
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
    string extractParameters(string name){
        int first=name.find("(");
        int last=name.find(")");
        return name.substr(first+1,last);
    }
    void executeCommandBlockStack(){
        int size=this->commandStack.size();
        PainFunctions func;
        for(int i=0;i<size;i++){
            commandBlock commandBlock=this->commandStack.top();
            string name=commandBlock.commandName;
//            if(name=="for"){
//                //func.painFor(this->fileLines,this->extractParameters(name),commandBlock);
//            }
            cout<<name<<endl;
            cout<<this->extractParameters(name)<<endl;
            //func.painInsert(this->fileLines,this->data[],commandBlock);
            cout<<"commandBlock:"<<name<<" range:"<<commandBlock.start<<" / "
            <<commandBlock.end<<" content-range:"<<commandBlock.contentStart<<" / "<<commandBlock.contentEnd<<endl;
            commandStack.pop();

        }

    }
    void executeInsertBlockStack(){
        int size=this->insertBlockStack.size();
        PainFunctions func;
        for(int i=0;i<size;i++){
            func.painInsert(this->fileLines,this->insertBlockStack[i], this->data);
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

public:

    Pain(string path, map <string,string> data){
        this->file.open(path);
        this->data=data;
    }
    string implode(){
        string temp;
        for(int i=0;i<this->fileLines.size();i++){
            temp+=(this->fileLines[i])+"\n";
        }
        return temp;
    }
    void run(){
        this->runFileAnalysis();
        this->processCommandRangeStack();
        this->executeInsertBlockStack();
        this->executeCommandBlockStack();
        this->cleanUp();
        cout<<"____________________"<<endl;
        for(int i=0;i<this->fileLines.size();i++){
            cout<<i<<". "<<this->fileLines[i]<<endl;
        }
    }

};