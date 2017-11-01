'use strict';

const express = require('express');
const app = express();
const date = require('./modules/date');

// render
app.engine('html', require('ejs').renderFile);

app.use(express.static('static'));

app.get('/', function(req, res, next) {
	res.render('index.html');
});

app.get('/:date', function(req, res, next) {
	let dateParam = req.params.date;
	
	let toSend = date(dateParam);
	
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
