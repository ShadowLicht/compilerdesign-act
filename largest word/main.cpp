#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string compare_words(string word, string lrgword);

int main(int argc, char *argv[]) {
    ifstream readf;
    ofstream file;
    string word, largeword;

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
            if(word[i] == '-'){
                // split the word
                largeword = compare_words(word.substr(0, i), largeword);
                word = word.substr(i+1);
            }
        }
        largeword = compare_words(word, largeword);
    }

    // Close the input file
    readf.close();

    cout << "The largest word is: " << largeword << endl;

    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;


    // store the largest word
    file << "The largest word is: " << largeword << endl;

    file.close();

    return 0;

}

string compare_words(string word, string lrgword){

    if(word.length() > lrgword.length())
        return word;
    else
        return lrgword;
}


