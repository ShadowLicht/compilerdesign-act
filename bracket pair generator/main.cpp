#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generateBrackets(string &combi, string bracket, int open, int close, int n)
{

    if (open == n && close == n) {
        combi += bracket + " ";
        return;
    }

    if (open < n) {

        generateBrackets(combi, bracket + "[", open + 1, close, n);
    }

    if (close < open) {

        generateBrackets(combi, bracket + "]", open, close + 1, n);
    }
}

int main(int argc, char* argv[])
{
    //for file manip
    ifstream readf;
    ofstream file;

    //variables use as counters and for iteration
    int ctr = 0, j = 0, i = 0;
    //use as storage location for string inputs and outputs
    string combi, input, phr, digit;

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
    while (readf >> phr){
        input += phr;
        ctr++;
    }

    //close readf/ ifstream
    readf.close();

    //array integer
    int pairs [ctr];

    //extract digit from the string then store it to pairs
    for (i = 0; i < input.length(); i++) {
        if(isdigit(input[i])){
            digit+=input[i];

            if(!isdigit(input[i+1])){
                pairs[j] = stoi(digit);

                digit = "";
                j++;

            }
        }
    }

    // Open the input file
    file.open(argv[2]);

    // Check if the input file is open
    if (!file.is_open())
        cout << "Unable to open file " << argv[2] << endl;

    //run the function generateBrackets base on the number of inputs from file
    for(i = 0; i<ctr; i++){
        generateBrackets(combi, "", 0, 0, pairs[i]);
        cout<<"\nInput: "<<pairs[i]<<" (Given pairs of Brackets)"<<endl;
        cout<<"Output: "<<combi<<endl;

        file<<"\nInput: "<<pairs[i]<<" (Given pairs of Brackets)"<<endl;
        file<<"Output: "<<combi<<endl;
        combi = "";
    }

    //close ofstream
    file.close();






    return 0;
}
