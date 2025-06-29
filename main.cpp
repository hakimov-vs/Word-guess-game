#include <iostream>
#include <string>
#include <ctime>
#include "lib.h"

using namespace std;

int main() {
    srand(time(0));
    
    string words[20] = {
        "apple", "banana", "coffee", "house", "river",
        "mountain", "castle", "dragon", "forest", "flower",
        "planet", "rocket", "puzzle", "screen", "window",
        "mirror", "button", "guitar", "camera", "cookie"
    };
    bool used[20] = {false};
    
    int penaltyPoints = 0;
    int guessedWords = 0;
    
    while (true) {
        string word = chooseWord(words, used, 20);
        string hidden;
        showHiddenWord(word, hidden);
        
        while (hidden != word) {
            if (penaltyPoints >= 10 || guessedWords >= 5) {
                cout << endl << endl << "You guessed " << guessedWords << " words in total." << endl << endl;
                return 0;
            }
            
            char guess = getGuess();
            
            
            if (guess == '0') {
                cout << "Game ended by player." << endl;
                cout << "You guessed " << guessedWords << " word." << endl;
                return 0;
            }
            
            bool correct = updateHiddenWord(word, hidden, guess);
            if (!correct) {
                penaltyPoints++;
            }
            
            cout << "Penalty points: " << penaltyPoints << endl;
            cout << endl;
        }
        
        guessedWords++;
        cout << endl << endl << "Well done! You guessed the word: " << word << endl << endl << endl;
        burnPenaltyPoints(penaltyPoints);
    }

    return 0;
}
