var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var carRouter = require('./routes/car');
var ownerRouter = require('./routes/owner');
var carOwnerRouter = require('./routes/car_owner');

var app = express();

const helmet = require('helmet');
const cors = require('cors');

app.use(helmet());
app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/car', carRouter);
app.use('/owner', ownerRouter);
app.use('/car_owner', carOwnerRouter);

const basicAuth = require('express-basic-auth');
app.use(basicAuth({users: { 'admin': '1234' }}))

module.exports = app;