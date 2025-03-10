#include <vector>
using namespace std;

// Token class stores the type of token and its value
class Token {
public:
    string type;
    string value;
};

class CharMap{

    public:

        vector<string> keywords = {"int", "double", "char", "string", "boolean", "float", "short", "long", "for", "while", "if", "switch", "else", "do"};
        CharMap(string inp);


        // Function to get the next token from the input string
        Token getNextToken() {
            Token token;

            // Removing leading whitespaces
            while (input[0] == ' ') {
                input = input.substr(1);
            }
            //cout<<input<<endl;

            int spaceIndex = input.find(' ');

            // Checking for keyword
            for (auto it = keywords.begin(); it != keywords.end(); ++it) {
                if (*it == input.substr(0, spaceIndex)) {
                // Found it!
                    token.type = "KEYWORD";
                    token.value = input.substr(0, spaceIndex);
                    input = input.substr(spaceIndex);
                    return token;
                }
            }


            // Checking for equals sign
            if (input.find(";") == 0) {
                token.type = "SEMICOLON";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for MODULO sign
            if (input.find("(") == 0) {
                token.type = "LPAREN";
                token.value = "";
                input = input.substr(1);
                return token;
            }
            // Checking for MODULO sign
            if (input.find(")") == 0) {
                token.type = "RPAREN";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for MODULO sign
            if (input.find("print") == 0) {
                token.type = "PRINT";
                token.value = "";
                input = input.substr(5);
                return token;
            }

            // Checking for MODULO sign
            if (input.find(",") == 0) {
                token.type = "COMMA";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for equals sign
            if (input.find("=") == 0) {
                token.type = "ASSIGN_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for plus sign
            if (input.find("+") == 0) {
                token.type = "PLUS_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for minus sign
            if (input.find("-") == 0) {
                token.type = "MINUS_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for mult sign
            if (input.find("*") == 0) {
                token.type = "MULT_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for divide sign
            if (input.find("/") == 0) {
                token.type = "DIV_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for MODULO sign
            if (input.find("%") == 0) {
                token.type = "MOD_OP";
                token.value = "";
                input = input.substr(1);
                return token;
            }

            // Checking for string value
            if (input.find("\"") == 0) {
                size_t endIndex = input.find("\"", 1);  // Find the index of the next occurrence of "
                while (endIndex != string::npos && input[endIndex-1] == '\\') {
                // If the " character is escaped with a backslash, find the next occurrence of "
                    endIndex = input.find("\"", endIndex + 1);
                }

                if (endIndex == string::npos) {
                    // If no matching " character is found, return an error token
                    token.type = "ERROR";
                    token.value = "Missing closing double quote";
                    return token;
                }

                token.type = "STRING";
                token.value = input.substr(0, endIndex+1);
                input = input.substr(endIndex+1);
                return token;
            }
            // Checking for char value
            if (input.find('\'') == 0) {
                int endIndex = 1;
                while (endIndex < input.size() && !(input[endIndex] == '\'' && input[endIndex-1] != '\\')) {
                endIndex++;
                }

                token.type = "CHAR";
                token.value = input.substr(0, endIndex+1);
                input = input.substr(endIndex+1);
                return token;
                }


            // Checking for identifier
            if (isalpha(input[0])) {
                int endIndex = 1;
                while (endIndex < input.size() && isalpha(input[endIndex]) || isdigit(input[endIndex])) {
                    endIndex++;
                }
                token.type = "ID";
                token.value = input.substr(0, endIndex);
                input = input.substr(endIndex);
                return token;
            }


            // Checking for a number literal, assuming only single digit numbers are used
            if (isdigit(input[0])) {
                int endIndex = 1;
                while (endIndex < input.size() && isdigit(input[endIndex])) {
                    endIndex++;
                }
                token.type = "NUM";
                token.value = input.substr(0, endIndex);
                input = input.substr(endIndex);
                return token;
            }


            // If nothing matches, return an empty token
            else {
                token.type = "";
                token.value = "";
            }

            return token;
        }


    private:
        string input;






};

CharMap::CharMap(string inp){

    input = inp;

}







