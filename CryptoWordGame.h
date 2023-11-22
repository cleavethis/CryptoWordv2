/* Here I created the CryptoWordGame class and included a default constructor
   and included the wordlist header file to populate the word array and get a random 
   word.*/

#ifndef CRYPTOWORDGAME_H
#define CRYPTOWORDGAME_H

#include "CryptoWordList.h"

class CryptoWordGame {
public:
    CryptoWordGame();
    void playGame();    // See CryptoWordGame.cpp 

private:
    CryptoWordList wordList;
    void convertToLowercase(char* guessedword);
    bool isValidGuess(const char* guessedWord);
    void evaluateGuess(const char* guessedWord, const char* secretWord, int& correctLetters, int& correctPositions);
};

#endif 
