#include "lib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

using namespace std;

string chooseWord(string words[], bool used[], int size) {
    int index;
    do {
        index = rand() % size;
    } while (used[index]);
    used[index] = true;
    return words[index];
}

bool updateHiddenWord(string word, string &hidden, char guess) {
    bool found = false;
    for (int i = 0; i < (int)word.length(); i++) {
        if (word[i] == guess && hidden[i] == '.') {
            hidden[i] = guess;
            found = true;
        }
    }
    cout << "Curent word: " << hidden << endl;  
    return found;
}

void showHiddenWord(string word, string &hidden) {
    hidden = "";
    for (int i = 0; i < (int)word.length(); i++) {
        hidden += ".";
    }
    cout << "Guess the word: " << hidden << endl << endl;
}

char getGuess() {
    char ch;
    cout << "Enter a letter: ";
    ch = getch(); 
    
    cout << ch << endl; 
    
    return ch;
}

void burnPenaltyPoints(int &penalty) {
    penalty -= 5;
    if (penalty < 0) penalty = 0;
}

bool isGameOver(int penalty, int guessedCount) {
    if (penalty >= 10) {
        cout << "Game over! You have too many penaltie points." << endl;  
        return true;
    }
    if (guessedCount >= 5) {
        cout << "Congretulations! You guessed 5 words! You won." << endl;  
        return true;
    }
    return false;
}
