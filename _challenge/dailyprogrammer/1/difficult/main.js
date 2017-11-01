'use strict';

const readlineSync = require('readline-sync');

let solved = false,
    guesses = [0],
    tries = 0,
    lowerBound = 1,
    upperBound = 100;

function guessNumber(lowerBound, upperBound) {
    let guess = 0;
    while (guesses.indexOf(guess) > -1) {
        guess = Math.floor(Math.random() * (upperBound - lowerBound + 1)) + lowerBound;
    }
    guesses.push(guess);
    
    console.log(guess);
    let check = readlineSync.question('Is this your number? (y/n) >> ');
    let hint;
    
    if (check.toLowerCase() === 'y') {
        return null;
    } else if (check.toLowerCase() === 'n') {
        hint = readlineSync.question('Is it higher or lower? (h/l) >> ');
        
        if (hint.toLowerCase() === 'h') {
            return [guess + 1, null];
        } else if (hint.toLowerCase() === 'l') {
            return [null, guess - 1];
        }
    }
}

while (!solved) {
    tries++;
    let returnValue = guessNumber(lowerBound, upperBound);
    
    if (returnValue === null) {
        console.log(`It took me ${tries} tries`);
        solved = true;
    } else {
        if (returnValue[0] === null) {
            upperBound = returnValue[1];
        } else if (returnValue[1] === null) {
            lowerBound = returnValue[0];
        }
    }
}