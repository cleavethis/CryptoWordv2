/*This file holds the logic of the game. playGame() handles all of the user interaction and output display
  the user can choose a difficulty here as well.*/

#include "CryptoWordGame.h"
#include <iostream>
#include <iomanip>
#include <string>



using namespace std;
// Load words from the file
CryptoWordGame::CryptoWordGame() {
    
    wordList.loadWordsFromFile("KeyWords.txt");     // wordList is an object from CryptoWordList class
}

void CryptoWordGame::playGame() {
    char secretWord[6];
    char guessedWord[6];
    int chances = 6;

    char difficulty;
    cout << "Welcome to CryptoWord! Try to guess the 5-letter word." << endl << endl;

    cout << "Choose the difficulty level (E for Unlimited Attempts, N for Normal, H for Hard): " << endl;

    cin >> difficulty;

    /*Use a switch statement to allow user to select difficulty, by changing chances variable, 
      any input other than E or H will select normal. */

    switch (toupper(difficulty)) 
    {
    case 'E':
        chances = -1; 
        break;
    case 'H':
        chances = 5; 
        break;
        
    }

   string secretWordStr = wordList.getRandomWord();      

   strcpy_s(secretWord, secretWordStr.c_str());

    // Start the while loop on easy difficutly or while the user has chances remaining.
    while (chances != 0)    
    {
        cout << "Enter your guess";

        if (chances > 0)
        {
          cout << " (" << chances << " chances remaining) : ";
        }

        else
        {
            cout << ": ";
        }
            
        cin >> guessedWord;

        // The following functions convert, validate and check the guess against the secret word.
        convertToLowercase(guessedWord);
   
        if (!isValidGuess(guessedWord)) 
        {
            cout << "Please enter a 5-letter guess." << endl << endl;
            continue;
        }
        
        int correctLetters = 0;
        int correctPositions = 0;
        
        evaluateGuess(guessedWord, secretWord, correctLetters, correctPositions);
       
        // Check if the guessed word is correct
        if (correctPositions == 5)
        {
            cout << "Congratulations! You guessed the word correctly." << endl;         
            break;
        }
       // By setting chances = -1 for easy difficulty the following only decrements chances on default or Hard difficulty
        if (chances > 0) 
        {
            chances--;
        }

        if (chances == 0)
        {
            cout << "Sorry, you're out of chances. The correct word was: "
                << secretWord << endl;
        }

    }
}

     // Convert the guessed word to lowercase
void CryptoWordGame::convertToLowercase(char* guessedWord)
{
   for (int i = 0; i < 5; ++i) {
        guessedWord[i] = tolower(guessedWord[i]);
    }
}

     // Checks if guess is 5 alphabetic characters long
bool CryptoWordGame::isValidGuess(const char* guessedWord) 
{
    for (int i = 0; i < 5; ++i)
    {
        if (!isalpha(guessedWord[i]))
        {
            return false;
        }

    }
    return true;
}

void CryptoWordGame::evaluateGuess(const char* guessedWord, const char* secretWord, int& correctLetters, int& correctPositions)
{
    for (int i = 0; i < 5; ++i)
    {
        if (guessedWord[i] == secretWord[i])
        {
            cout << "Letter " << guessedWord[i] << " at position " << i + 1 << " is correct." << endl;
            correctPositions++;
        }

        else if (strchr(secretWord, guessedWord[i]) != nullptr)
        {
            cout << "Letter " << guessedWord[i] << " is in the word but not in the correct position." << endl;
            correctLetters++;
        }

        else
        {
            cout << "Letter " << guessedWord[i] << " is incorrect." << endl;
        }
        
    }
    cout << endl;
}