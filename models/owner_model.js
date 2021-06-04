const db = require('../database');

const owner = {
  getById: function(id, callback) {
    return db.query('select * from owner where owner_id = $1', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from owner', callback);
  },
  add: function(owner, callback) {
    return db.query(
      'insert into owner (firstname, lastname, address) values($1, $2, $3)',
      [owner.firstname, owner.lastname, owner.address],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from owner where owner_id = $1', [id], callback);
  },
  update: function(id, owner, callback) {
    return db.query(
      'update owner set firstname = $1, lastname = $2, address = $3 where owner_id = $4',
      [owner.firstname, owner.lastname, owner.address, id],
      callback
    );
  }
};
module.exports = owner;