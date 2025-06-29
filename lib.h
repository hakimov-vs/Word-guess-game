#include <string>
using namespace std;

string chooseWord(string words[], bool used[], int size);
void showHiddenWord(string word, string &hidden);
bool updateHiddenWord(string word, string &hidden, char guess);
char getGuess();
bool isGameOver(int penalty, int guessedCount);
void burnPenaltyPoints(int &penalty);
