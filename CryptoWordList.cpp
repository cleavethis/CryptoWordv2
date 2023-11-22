/*This implementation file handles all of the functionalty related to getting the words from 
  a given txt file. Here I generate a random seed, create my array from an input file, then
  select a random element from the array as the secretword.*/

#include "CryptoWordList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;


CryptoWordList::CryptoWordList() : wordCount(0) 
{
  
    srand(time(0));
}



// This function loads the words into the game from the given file
void CryptoWordList::loadWordsFromFile(const string& filename) {

    ifstream file(filename);

    if (file.is_open()) {
        string word;
        while (file >> word && wordCount < MAX_WORDS) {
            words[wordCount++] = word;
        }
        file.close();
    }

    else {
        cout << "Error: Unable to open file " << filename << endl;
    }
}



// Returns a random word from the words array
string CryptoWordList::getRandomWord() const {
    if (wordCount == 0) {

        cout << "Error: Word list is empty." << endl;
        
        return "";
    }

    return words[rand() % wordCount];
}