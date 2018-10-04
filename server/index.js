var express = requiere('express');
var socketIo = require('socket.io');
var http = require('http');
var SerialPort = require('serialport');
var ReadLine = require('readline');
var RawParser = require('./raw_parser');

var app = express();
var server = http.createServer(app);
var io = socketIo.listen(server);

var port = new SerialPort('COM8',{
    baudRate: 9600
});

parser = port.pipe(new RawParser());

parser.on('data', function(data){
    console.log(data);
    var result = {
        origen : data[0].toString(16),
        destino : data[1].toString(16),
        longitud : data[2],
        payload : {},
        checksum : data[data.length - 1].toString(16)
    }
    for(var i = 3; i<data.length -2; i+=3){
        var buf = Buffer.from([data[i+1], data[i+2]]);
        result.payload[data[i].toString(16)] = buf.readInt16BE(0);
      }
    console.log(result);
});

server.listen(9000, () => {
    console.log('server on port 9000');
});