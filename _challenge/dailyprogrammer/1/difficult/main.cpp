#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int inVector(int elem, const vector<int>& checkVector);
int* checkGuess(int lowerBound, int upperBound, vector<int>& guesses);
int generateRandomNumber(int lowerBound, int upperBound);

int main() {
    vector<int> guesses;
    bool solved = false;
    int tries = 0;
    int lowerBound = 1;
    int upperBound = 100;
    guesses.push_back(0);
    
    while (!solved) {
        tries++;
        int* returnValue = checkGuess(lowerBound, upperBound, guesses);
        
        if (returnValue[0] == -1 && returnValue[1] != -1) {
            upperBound = returnValue[1];
        } else if (returnValue[0] != -1 && returnValue[1] == -1) {
            lowerBound = returnValue[0];
        } else {
            cout << "It took me " << tries << " tries" << endl;
            solved = true;
        }
        delete [] returnValue;
    }
}

int inVector(int elem, const vector<int>& checkVector) {
    for (size_t i = 0; i < checkVector.size(); i++) {
        if (checkVector[i] == elem){
            return i;
        }
    }
    return -1;
}

int generateRandomNumber(int lowerBound, int upperBound) {
    srand(time(nullptr));
    int random = rand() % (upperBound - lowerBound + 1) + lowerBound;
    return random;
}

int* checkGuess(int lowerBound, int upperBound, vector<int>& guesses) {
    int guess = 0;
    int* returnArr = new int[2];
    returnArr[0] = -1;
    returnArr[1] = -1;
    
    while (inVector(guess, guesses) > -1) {
        guess = generateRandomNumber(lowerBound, upperBound);
    }
    guesses.push_back(guess);
    
    cout << guess << endl;
    string check;
    cout << "Is this your number? (y/n) >> ";
    cin >> check;
    
    if (check == "n") {
        string hint;
        cout << "Is it higher or lower? (h/l) >> ";
        cin >> hint;
        
        if (hint == "h") {
            returnArr[0] = guess + 1;
        } else if (hint == "l") {
            returnArr[1] = guess - 1;
        }
    }
    return returnArr;
}