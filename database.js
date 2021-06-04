const Pool = require('pg').Pool;
const connection = new Pool({
  user: 'iipgcgmkbqbupw',
  host: 'ec2-176-34-222-188.eu-west-1.compute.amazonaws.com',
  database: 'd5k4vl02hgvti6',
  password: '22940ddfee30b1bea39c930c5e6f0cbcc38ff0122ca55fb12bba54e8f5f97da0',
  port: 5432,
  ssl: { rejectUnauthorized: false }
});
module.exports = connection;