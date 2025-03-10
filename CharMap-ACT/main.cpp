#include <iostream>
#include <string>
#include <fstream>
#include "CharMap.h"

using namespace std;

 int main(int argc, char* argv[]) {
    char c;
    int chtype = 0;
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


    CharMap cm;

    // Read the input word by word
    while (getline(readf, str)){

        str1 += str + '\n';
    }

    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;


    for(int i = 0; i<str1.length(); i++){
        chtype = cm.identify(str1[i]);
        cout<<"Char "<<str1[i]<<": type: "<<chtype<<endl;
        file<<"Char "<<str1[i]<<": type: "<<chtype<<endl;
    }



    //close readf/ ifstream
    readf.close();
    //close ofstream
    file.close();

    return 0;

 }

