const db = require('../database');

const car = {
  getById: function(id, callback) {
    return db.query('select * from car where car_id = $1', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from car', callback);
  },
  add: function(car, callback) {
    return db.query(
      'insert into car (brand, model, year_of_manufacture) values ($1, $2, $3)',
      [car.brand, car.model, car.year_of_manufacture],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from car where car_id = $1', [id], callback);
  },
  update: function(id, car, callback) {
    return db.query(
      'update car set brand = $1, model = $2, year_of_manufacture = $3 where car_id = $4',
      [car.brand, car.model, car.year_of_manufacture, id],
      callback
    );
  }
};
module.exports = car;