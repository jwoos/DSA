'use strict';

const readlineSync = require('readline-sync');

let text = readlineSync.question('Please enter a string: ');
let shift = parseInt(readlineSync.question('How much should it be shifted by? '));

let encoded = '';

for (let letter of text) {
	if (letter === letter.toLowerCase()) {
		let diff = letter.charCodeAt(0) - 97;
		let shifted = (diff + shift) % 26;
		encoded += String.fromCharCode(shifted + 97);
	} else if (letter === letter.toUpperCase()) {
		let diff = letter.charCodeAt(0) - 65;
		let shifted = (diff + shift) % 26;
		encoded += String.fromCharCode(shifted + 65);
	} else {
		encoded += letter;
	}
}

console.log('The encrypted string is: %s', encoded);
