#include "dataStructures.h"
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class PainFunctions{
    unsigned int addedRowsCounter=0;
public:
      void painFor(vector <string> &fileLines,int n, commandBlock &commandBlock){
        int contentRangeLen=commandBlock.contentEnd-commandBlock.contentStart;
        contentRangeLen == 0 ? contentRangeLen = (1+this->addedRowsCounter) : contentRangeLen += this->addedRowsCounter;
        vector <string> content;
        content = {fileLines.begin() + commandBlock.contentStart, fileLines.begin()  + commandBlock.contentEnd+1};
        fileLines.reserve(fileLines.size()+(n*contentRangeLen));

        for(int i=0;i<n-1;i++){
            fileLines.insert((fileLines.begin()+commandBlock.contentEnd+1),content.begin(),content.end());
            this->addedRowsCounter+=(contentRangeLen*content.size());
        }
      }
      void painIf(vector <string> &fileLines,int n, commandBlock &commandBlock){

      }
      void painInsert(vector <string> &fileLines,string data, commandBlock &commandBlock){
          cout<<data<<endl;
          int contentRangeLen=commandBlock.end-commandBlock.start;
          fileLines.reserve(fileLines.size()+(2*contentRangeLen));
          fileLines.insert((fileLines.begin()+commandBlock.start),data);
      }

};