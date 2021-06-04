const db = require('../database');

const owner = {
  getById: function(id, callback) {
    return db.query('select * from owner where owner_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from owner', callback);
  },
  add: function(owner, callback) {
    return db.query(
      'insert into owner (firstname, lastname, address) values(?,?,?)',
      [owner.firstname, owner.lastname, owner.address],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from owner where owner_id=?', [id], callback);
  },
  update: function(id, owner, callback) {
    return db.query(
      'update owner set firstname=?, lastname=?, address=? where owner_id=?',
      [owner.firstname, owner.lastname, owner.address, id],
      callback
    );
  }
};
module.exports = owner;