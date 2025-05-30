const fs = require('fs');

const readStream = fs.createReadStream('./doc/test2.txt');
const writeStream = fs.createWriteStream('./doc/test3.txt');

readStream.on('data',(chunk) =>{
    console.log('-----New Chunk-----');
    console.log(chunk.toString());

    writeStream.write(chunk)
})