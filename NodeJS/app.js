const express = require('express');

//express app
const app = express();

//Register view engine
app.set('view engine', 'ejs');

//Listen for request
app.listen(3000);

app.get('/', (req,res) => {
    //res.send('<p>Home Page</p>');
    res.sendFile('./views/index.html',{root:__dirname});
});

app.get('/about', (req,res) => {
    res.sendFile('./views/about.html',{root:__dirname});
    //res.send('<p>About Page</p>');
});

//Redirect
app.get('/about-me', (req,res) => {
    res.redirect('/about');
});

//404 error
app.use((req,res) => {
    res.status(404).sendFile('./views/404.html',{root:__dirname});
})