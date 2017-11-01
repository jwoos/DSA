'use strict';

const express = require('express');
const app = express();

const pg = require('pg');
const pgString = process.env.DATABASE_URL || 'postgres://ubuntu:123456789@localhost/links';
if (process.env.DEV_ENV === 'heroku') {
    pg.defaults.ssl = true;
}

app.engine('html', require('ejs').renderFile);

app.use(express.static('static'));

app.get('/', function(req, res, next) {
    res.render('index.html');
});

app.get('/new/:url', function(req, res, next) {
    let url = req.params.url;
    let toReturn = {};

    let gettingQuery;
    
    let validPattern = /^(https|http)?(:\/\/)?(www\.)?\w+\.(\w+)(\.\w+)?(\/\w+)*/;
    if (!validPattern.test(url)) {
        toReturn.error = true;
        res.send(toReturn);
    }
    
    pg.connect(pgString, function(err, client, done) {
        if (err) {
            console.log('Error fetching client from pool', err);
            done();
            res.send(err);
        }
        
        let insertionQuery = client.query(`INSERT INTO links(url) values('${url}')`);
        insertionQuery.on('error', function(err) {
            done();
            res.send(err);
        });
    
        insertionQuery.on('end', function() {
            console.log('inserted');
            gettingQuery = client.query(`SELECT * FROM links WHERE url='${url}'`, function(err, result) {
                if (err) {
                    toReturn.error = err;
                    res.send(toReturn);
                }
                console.log(result);
                toReturn.original_url = result.rows[result.rows.length - 1].url;
                toReturn.short_url = 'http://fcc-jwoos.c9users.io/' + result.rows[result.rows.length - 1].id;
            });
            
            gettingQuery.on('end', function() {
                done();
                return res.send(toReturn); 
            });
        });
    });
});

app.get('/:number', function(req, res, next) {
    let number = req.params.number;
    
    if (!number.match(/\d+/)) {
        next();
    }
    
    pg.connect(pgString, function(err, client, done) {
        if (err) {
            return console.log('Error fetching client from pool', err);
        }
        
        client.query(`SELECT * FROM links WHERE id=${number}`, function(err, results) {
            done();
            if (err) {
                console.log(err);
            } else {
                if (results.rows.length) {
                    res.redirect('//' + results.rows[0].url);
                } else {
                    next();
                }
            }
        });
    });
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
		res.send(err);
	}
});

const PORT = process.env.PORT || 8080;

app.listen(PORT);
