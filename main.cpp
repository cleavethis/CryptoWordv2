/* Rick Richmond CS40 Project -- CryptoWord 
   This project is my attempt to recrate the functionality of the Internet game Wordle.
   The user is given 6 chances to guess a 5 letter word, and is given feedback after each
   guess. I used a list of 100 words that were picked from the actual valid words that wordle uses.
   I tried to keep main as clean and readable as possible so I used multiple implementaiton and specification
   files.*/

#include "CryptoWordGame.h"
#include <iostream>
using namespace std;

// Create a CryptoWordGame object called game then call the playgame member function.
int main() {
    
    bool playAgain = true;

    while (playAgain) 
    {
        CryptoWordGame game;
        
        game.playGame();

        cout << "Do you want to play again? (y/n): " << endl;
        char response;
        cin >> response;

        playAgain = (response == 'y' || response == 'Y');
    }

    cout << "Thanks for playing CryptoWord! Goodbye." << endl;
     

    return 0;
}