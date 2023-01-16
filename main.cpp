#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <limits>
#include <map>
#include <functional>
#include "engine/pain/pain.cpp"
using namespace std;
//
//
//
//fstream& GotoLine(fstream& file, unsigned int num){
//    file.seekg(ios::beg);
//    for(int i=0; i < num; ++i){
//        file.ignore(std::numeric_limits<streamsize>::max(),'\n');
//    }
//    return file;
//}
//fstream& GotoLinePut(fstream& file, unsigned int num){
//    file.seekp(ios::beg);
//    for(int i=0; i < num; ++i){
//        file.ignore(std::numeric_limits<streamsize>::max(),'\n');
//    }
//    return file;
//}
//
//
//void painFor(int n, string fileName, commandBlock &commandBlock){
//    vector <string> tempLines;
//    string tempLine;
//    fstream file(fileName);
//    int contentRange=commandBlock.contentEnd-commandBlock.contentStart;
//    contentRange ==0 ? contentRange =1 : contentRange = contentRange;
//    GotoLine(file,commandBlock.contentStart);
//    cout<<contentRange<<endl;
//    for(int i=0;i<contentRange;i++){
//        getline(file,tempLine);
//        cout<<tempLine<<endl;
//        tempLines.push_back(tempLine);
//    }
//    file.close();
//    fstream fileIn;
//    fileIn.open(fileName,ios::app);
//    GotoLinePut(fileIn,commandBlock.contentStart);
//    cout<<fileIn.bad()<<endl;
//    for(int i=0;i<n;i++){
//        fileIn<<"xdddddddddd\n";
//    }
//
//    fileIn.close();
//}
//
//
//void detectCommand(string line,int lineNo){
//    commandRange range;
//    range.start=line.find("@");
//    range.end=line.find("@",range.start+1);
//    range.lineNo=lineNo;
//    if(range.start != -1 and range.end != -1 ){
//        commandRangeStack.push_back(range);
//    }
//}
//
//
//
//void processCommandRangeStack(commandRange commandStartRange,commandRange commandEndRange,fstream& file){
//    string line;
//    commandBlock commandBlock;
//    commandBlock.start=commandStartRange.lineNo;
//    commandBlock.end=commandEndRange.lineNo;
//    commandBlock.contentStart=commandBlock.start+1;
//    commandBlock.contentEnd=commandBlock.end-1;
//    GotoLine(file,commandStartRange.lineNo);
//    getline(file,line);
//    int range=commandStartRange.end-commandStartRange.start;
//    commandBlock.commandName=line.substr(commandStartRange.start,range);
//    commandStack.push(commandBlock);
//}
//void executeCommandBlock(commandBlock &commandBlock,string fileName){
//    string name=commandBlock.commandName;
//    cout<<name<<endl;
//    if(name =="@for"){
//        painFor(5,fileName, commandBlock);
//    }
//
//}
int main() {

//    fstream file;
//    string line;
//    file.open("test.pain");
//    int lineNo=0;
//    while(getline(file,line)){
//        detectCommand(line,lineNo);
//        lineNo++;
//    }
//    file.close();
//    file.open("test.pain");
//    int size=commandRangeStack.size();
//    for(int i =0;i<size/2;i++){
//        commandRange commandStartRange = commandRangeStack.front();
//        commandRange commandEndRange = commandRangeStack.back();
//
//        cout<<commandStartRange.start<<" "<<commandStartRange.end<<" "<<commandStartRange.lineNo<<endl;
//        cout<<commandEndRange.start<<" "<<commandEndRange.end<<" "<<commandEndRange.lineNo<<endl;
//        cout<<"______________________"<<endl;
//        processCommandRangeStack(commandStartRange,commandEndRange,file);
//
//        commandRangeStack.pop_back();
//        commandRangeStack.erase(commandRangeStack.begin());
//    }
//
//
//    size=commandStack.size();
//    file.close();
//    for(int i=0;i<size;i++){
//
//        executeCommandBlock(commandStack.top(), "test.pain");
//        commandStack.pop();
//    }
//    file.close();

    Pain pain("test.pain.html");
    pain.run();
}
