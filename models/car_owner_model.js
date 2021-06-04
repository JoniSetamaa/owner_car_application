const db = require('../database');

const car_owner = {
  getCarOwnersById: function(id, callback) {
    return db.query('select * from car_owner where owner_id = $1', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from car_owner', callback);
  },
  add: function(car_owner, callback) {
    return db.query(
      'insert into car_owner (car_id, owner_id) values($1, $2)',
      [car_owner.car_id, car_owner.owner_id],
      callback
    );
  },
  delete: function(car_id, owner_id, callback) {
    return db.query('delete from car_owner where car_id = $1 and owner_id = $2', [car_id, owner_id], callback);
  },
  update: function(car_id, owner_id, car_owner, callback) {
    return db.query(
      'update car_owner set car_id = $1, owner_id = $2 where car_id = $3 and owner_id = $4',
      [car_owner.car_id, car_owner.owner_id, car_id, owner_id],
      callback
    );
  }
};
module.exports = car_owner;