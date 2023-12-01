#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


bool isStringInArray(string str, string array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (str == array[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("program.cpp");

    if (!inputFile.is_open()) {
        cout << "File is not found." << endl;
        return 1;
    }

    int Count=0;
    int typeCount=0;
    string line;
    string funcNames[100];
    string funcType[100];
    string type;

    while(getline(inputFile, line)) {
        istringstream iss(line);
        string word;

        while(iss>>word) {
            if(word=="int" || word=="void" || word=="float" || word=="string" || word=="bool" || word=="double" || word=="char" || word=="long" || word=="short") {

                type=word;
                iss>>word;
                size_t position=word.find("(");
                if(position!=string::npos) {
                    string funcName=word.substr(0,position);
                    funcType[typeCount++]=type;
                    if(funcName=="main"){
                        continue;
                    }
                    else{

                    if(!isStringInArray(funcName,funcNames,Count)) {
                        funcNames[Count++]=funcName;
                    }
                    }
                }
            }
        }
    }

    inputFile.close();

    cout<<"Total number of user-defined functions: "<<Count<<endl;
    for(int i = 0; i < Count; ++i) {
        cout<<"Function-"<<i + 1<<": "<<funcNames[i]<<"   Type of this function is :"<<funcType[i]<<endl;
    }



    return 0;
}
