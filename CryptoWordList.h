/* In this file I define a new class to handle the functionality of getting 
   the words from the file and choosing a random word from among the given list, I used
   a hardcoded list of 100 words.*/

#ifndef CRYPTOWORDLIST_H
#define CRYPTOWORDLIST_H
#include <string>
using namespace std;

class CryptoWordList {

public:
    CryptoWordList();
    
    void loadWordsFromFile(const string& filename);
    string getRandomWord() const;


private:
    int wordCount;
    static const int MAX_WORDS = 100;
    string words[MAX_WORDS];
};

#endif 
