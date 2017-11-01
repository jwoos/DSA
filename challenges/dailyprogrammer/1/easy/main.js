'use strict';

const readlineSync = require('readline-sync');
const fs = require('fs');

let name = readlineSync.question('Enter your name: ');
let age = readlineSync.question('Enter your age: ');
let username = readlineSync.question('Etner your username: ');

let sentence = `Your name is ${name}, you are ${age} years old, and your username is ${username}\n`;

console.log(sentence);

fs.writeFileSync('log.txt', sentence, 'utf8');
