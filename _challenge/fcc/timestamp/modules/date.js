'use strict';

module.exports = function(date) {
    let toSend = {
    	unix: null,
    	natural: null
    };
    
    let monthMap = {
    	0: 'January',
    	1: 'February',
    	2: 'March',
    	3: 'April',
    	4: 'May',
    	5: 'June',
    	6: 'July',
    	7: 'August',
    	8: 'September',
    	9: 'October',
    	10: 'November',
    	11: 'December'
    };
    
    if (isNaN(Number(date))) {
    	let dateObj = new Date(date);
    	toSend.natural = date;
    	toSend.unix = dateObj.getTime() / 1000;
    } else {
    	let dateObj = new Date(date * 1000);
    	if (!(isNaN(dateObj.getFullYear()) || !monthMap[dateObj.getUTCMonth()] || !(date.length == 10))) {
    		toSend.unix = dateObj.getTime() / 1000;
    		toSend.natural = monthMap[dateObj.getUTCMonth()] + ' ' + dateObj.getUTCDate() + ', ' + dateObj.getUTCFullYear();
    	}
    }
    
    return toSend;
};
