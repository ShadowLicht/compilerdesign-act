#include <iostream>
#include <string>
#include <fstream>
#include "CharMap.h"

using namespace std;

 int main(int argc, char* argv[]) {
    char c;
    string str;
    string str1;

    //for file manip
    ifstream readf;
    ofstream file;


    if (argc != 3) {
    cout << "Usage: " << argv[0] << endl;
    }

    // Open the input file
    readf.open(argv[1]);



    // Check if the input file is open
    if (!readf.is_open()) {
        cout << "Error: Unable to open file " << argv[1] << endl;
    }
    // Open the input file
    file.open(argv[2]);
    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;



    Token token;
    // Read the input word by word
    while (getline(readf, str)){



    CharMap cm(str);


    while ((token = cm.getNextToken()).type != "") {
        // cout<<lex.getNextToken().value<<endl;

        cout << token.type;
        file << token.type;
        if(token.value != ""){
            cout << "(\"" << token.value <<"\") ";
            file << "(\"" << token.value <<"\") ";
        }
        else{
            cout << " ";
            file << " ";
        }
    }


    }



    //close readf/ ifstream
    readf.close();
    //close ofstream
    file.close();

    return 0;

 }

