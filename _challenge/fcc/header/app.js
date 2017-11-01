'use strict';

const express = require('express');
const app = express();

app.get('/', function(req, res, next) {
    let toSend = {};
    
    toSend.ipaddress = req.headers['x-forwarded-for'];
    toSend.language = req.headers['accept-language'].split(',')[0];
    toSend.software = req.headers['user-agent'].match(/\(([\w\s;.]+)\)/)[1];
    console.log(toSend);
    res.send(toSend);
});

// handle 404
app.use(function(req, res, next) {
	res.status(404).send('Sorry can\'t find that!');
});

// error handling
app.use(function(err, req, res, next) {
	if (req.xhr) {
		res.status(500).send({ error: 'Error' });
	} else {
		res.send('Error');
		res.send(err);
	}
});

const PORT = process.env.PORT || 8080;

app.listen(PORT);