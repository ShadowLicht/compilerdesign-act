#include "CharMap.h"
using namespace std;




class Token {
public:
    int tcode;
    string type;
    string value;
};


class Scanner {

    private:
        CharMap* cmap;
        string input;
    public:

        Scanner(string inp);

        Token getNextToken();
        string strtrim(string str, int sindex);

        void setCharMap(CharMap* cmap);

        enum TokenCode {
            ERROR = 0,
            WORD = 1,
            NUMBER = 2,
            E0F = 3
        };
        static const string TokenSTR[];

};

const string Scanner::TokenSTR[] = {"ERROR", "WORD", "NUMBER", "eof"};



void Scanner::setCharMap(CharMap* cmap) {

    this->cmap = cmap;

}


Scanner::Scanner(string inp){

 input = inp;


}

Token Scanner::getNextToken() {

            Token token;
            string tvalue = "";
            int dec_ctr = 0;
            bool haslet = false;

            int i = 0;

            do{
                if(cmap->identify(input[i]) == 0){

                    input = strtrim(input, i+1);
                    continue;
                }



                if(cmap->identify(input[i]) == 1){

                    while (cmap->identify(input[i]) != 0 && (cmap->identify(input[i]) == 1 || cmap->identify(input[i]) == 2)) {
                        tvalue += input[i];
                        i++;
                    }
                        token.tcode = WORD;
                        token.type = TokenSTR[WORD];
                        token.value = tvalue;

                        tvalue = "";

                        input = strtrim(input, i);

                        break;
                }


                if(cmap->identify(input[i]) == 2){


                    while (cmap->identify(input[i]) != 0 && cmap->identify(input[i]) != 5) {

                        if(cmap->identify(input[i]) == 1){
                            haslet = true;
                        }

                        if(input[i] == '.'){
                            dec_ctr++;
                        }

                        tvalue += input[i];

                        i++;


                    }


                    if(haslet == true || dec_ctr > 1 ){

                        token.tcode = ERROR;
                        token.type = TokenSTR[ERROR];
                        token.value = tvalue;

                        tvalue = "";
                        input = strtrim(input, i);


                        break;
                    }

                    else{
                        token.tcode = NUMBER;
                        token.type = TokenSTR[NUMBER];
                        token.value = tvalue;

                        tvalue = "";

                        input = strtrim(input, i);

                        break;
                    }

                }

        if(cmap->identify(input[i]) == 3){

            while (cmap->identify(input[i]) != 0) {
                tvalue += input[i];
                i++;
            }

            token.tcode = ERROR;
            token.type = TokenSTR[ERROR];
            token.value = tvalue;

            tvalue = "";

            input = strtrim(input, i);
            break;

        }
        else{

            token.type = "";
            token.value = "";

        }




        i++;

    }while(i < input.length());

    // If nothing matches, return an empty token
    if (token.type.empty() && token.value.empty()) {

        token.tcode = E0F;
        token.type = TokenSTR[E0F];
        token.value = "";
    }

    return token;
}

string Scanner::strtrim(string str, int sindex){
    int i = sindex;
    string trimmedstr = "";

    while(i< str.length()){

        trimmedstr += str[i];
        i++;
    }

    return trimmedstr;

}

