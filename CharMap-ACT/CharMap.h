using namespace std;
class CharMap{

    private:

    public:
        CharMap();
        int identify(char c);
        int allchar[256] = {5};



};

CharMap::CharMap(){

    int i = 0;

    for(i = 65; i<=90; i++)
        allchar[i] = 1;
    for(i = 97; i<=122; i++)
        allchar[i] = 1;
    for(i = 48; i<=57; i++)
        allchar[i] = 2;
    for(i = 35; i<=47; i++)
        allchar[i] = 3;
    for(i = 58; i<=64; i++)
        allchar[i] = 3;
    for(i = 91; i<=96; i++)
        allchar[i] = 3;
    for(i = 123; i<=126; i++)
        allchar[i] = 3;
    for(i = 145; i<=148; i++)
        allchar[i] = 4;
    for(i = 9; i<=10; i++)
        allchar[i] = 0;
    allchar[34] = 0;
    allchar[32] = 0;
    allchar[33] = 3;





}

int CharMap::identify(char c){


    return allchar[c];

}



