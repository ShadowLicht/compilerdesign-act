#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream readf;
    ofstream file;
    string word;
    int counter;

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

    for(i = 0; i<word.length()-2; i++){

       if(tolower(word[i]) == 'e' && tolower(word[i+2]) == 'g'
          || tolower(word[i]) == 'g' && tolower(word[i+2]) == 'e')
        counter++;
    }

    cout << "Count: "<< word<<" -> "<<counter;



    // Close the input file
    readf.close();



    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;


    // store the count
    file << "Count: "<< word<<" -> "<<counter;

    file.close();

    return 0;

}



