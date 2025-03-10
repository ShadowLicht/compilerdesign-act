#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream readf;
    ofstream file;
    string word;
    char temp;

    int i = 0, j = 0;

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


    // Read the input word by word
    readf >> word;
    cout<<"Word: "<<word<<endl;

    for(i = 0; i<word.length(); i++){

        if(isalpha(tolower(word[i]))){

            for(j = 0; j<word.length(); j++){

                if(isalpha(tolower(word[j]))){

                    if(tolower(word[i])<tolower(word[j])){
                        temp = word[i];
                        word[i] = word[j];
                        word[j] = temp;
                    }

                }

            }

        }
    }

    cout << "Sorted: "<< word;



    // Close the input file
    readf.close();



    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;


    // store the sorted word
    file << "Sorted: "<< word;

    file.close();

    return 0;

}



