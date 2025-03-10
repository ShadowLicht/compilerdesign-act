#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream readf;
    ofstream file;
    string word, repeated;
    int tempcount = 0, maxcount = 0;


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
    while (readf >> word) {

        for(int i = 0; i < word.length(); i++){
            for(int j = i+1; j<word.length(); j++){

                if(tolower(word[i]) == tolower(word[j]))
                    tempcount++;
            }
        }

        if(tempcount>maxcount){
            maxcount = tempcount;
            repeated = word;
        }

        tempcount = 0;
    }

    // Close the input file
    readf.close();

    cout << "Word which has the highest number of repeated letters: " << repeated << endl;

    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;


    // store the word with highest number of repeated letter
    file << "Word which has the highest number of repeated letters: " << repeated << endl;

    file.close();

    return 0;

}




