'use strict';

const pg = require('pg');
const pgString = process.env.DATABASE_URL || 'postgres://ubuntu:123456789@localhost/links';
if (process.env.DEV_ENV === 'heroku') {
    pg.defaults.ssl = true;
}

pg.connect(pgString, function(err, client, done) {
    if (err) {
        return console.log(err);
    }
    
    let query = client.query(`
        CREATE TABLE links(
            id SERIAL PRIMARY KEY NOT NULL,
            url TEXT NOT NULL
        )
    `);
    
    query.on('error', function(err) {
        console.log(err);
    });
    
    query.on('end', function() {
        done();
    });
});