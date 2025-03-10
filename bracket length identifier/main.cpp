#include <iostream>
#include <fstream>

using namespace std;

int findvalidlength(string s) {

    int open = 0, close = 0, vallength = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '[') {
            open++;
        }
        else if(s[i] == ']' && close < open) {
            close++;
        }

        if(open >= close) {
            vallength = 2*close;
        }
    }


    return vallength;

}

int main(int argc, char* argv[]) {

     //for file manip
    ifstream readf;
    ofstream file;

    string brackets;
    int val_length;

    // Check if the number of command line arguments is correct
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



    // Read the input word by word
    while (readf >> brackets){

        val_length = findvalidlength(brackets);
        cout << "Original Brackets string: " << brackets << endl;
        cout << "Length of longest Brackets: " << val_length << "\n\n";
        file << "Original Brackets string: " << brackets << endl;
        file << "Length of longest Brackets: " << val_length << "\n\n";

    }

    readf.close();
    file.close();

    return 0;
}
