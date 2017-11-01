'use strict';

const readlineSync = require('readline-sync');

let conversions = {
  f: {
    c: (currentTemp) => {
      return (currentTemp - 32) * 5 / 9;
    },
    k: (currentTemp) => {
      return conversions['f']['c'](current_temp) + 273.15;
    }
  },
  c: {
    f: (currentTemp) => {
      return (currentTemp * 9 / 5) + 32;
    },
    k: (currentTemp) => {
      return currentTemp + 273.15;
    }
  },
  k: {
    c: (currentTemp) => {
      return currentTemp - 273.15;
    },
    f: (currentTemp) => {
      return conversions['c']['f'](current_temp - 273.15);
    }
  }
};

function tip(amount, percentage) {
  return total + (total * percentage / 100);
}

let action = readlineSync.question('Tip or temperature?\n');

if (action.lower() === 'tip') {
  let total = parseFloat(readlineSync.question('What is the total?\n'));
  let rate = parseFloat(readlineSync.question('What is the tipping rate?\n'));
  console.log(tip(total, rate));
} else {
  let currentTemp = parseFloat(readlinesync.question('What is the current temperature\n'));
  let fromUnit = readlinesync.question('What is the current unit?\n');
  let toUnit = readlinesync.question('What unit should it be convered to?\n');
  console.log(conversions[fromUnit][toUnit](currentTemp));
}

