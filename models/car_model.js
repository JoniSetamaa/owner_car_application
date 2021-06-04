const db = require('../database');

const car = {
  getById: function(id, callback) {
    return db.query('select * from car where car_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from car', callback);
  },
  add: function(car, callback) {
    return db.query(
      'insert into car (brand, model, year_of_manufacture) values (?,?,?)',
      [car.brand, car.model, car.year_of_manufacture],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from car where car_id=?', [id], callback);
  },
  update: function(id, car, callback) {
    return db.query(
      'update car set brand=?, model=?, year_year_of_manufacture=? where car_id=?',
      [car.brand, car.model, car.year_of_manufacture, id],
      callback
    );
  }
};
module.exports = car;