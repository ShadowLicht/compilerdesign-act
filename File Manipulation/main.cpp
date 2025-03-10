#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream readf;
    ofstream file;
    string line;


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

    else{
        while (!readf.eof()) {

            getline(readf, line);
            cout << line << endl;

        }

    }

    // Close the input file
    readf.close();


    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;




    for(int i = 0; i<argc; i++){

        if(i==0)
            file << "The path of the executable file: " << argv[i] << endl;
        else
            file << "File #" << i << ": " << argv[i] << endl;

    }


    file.close();

    return 0;

}




