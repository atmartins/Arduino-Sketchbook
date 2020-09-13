// const SerialPort = require('serialserialPort');
// const Readline = require('@serialserialPort/parser-readline');

// const serialPort = new SerialPort('COM3', { baudRate: 9600 });
// const parser = serialPort.pipe(new Readline({ delimiter: '\n' }));
 
// // Read the serialPort data
// serialPort.on("open", () => {
//     console.log('serial serialPort open');

// });

// // serialPort.write('h', (err) => {
// //     if (err) {
// //         return console.log('Error on write: ', err.message);
// //     }
// //     console.log('message written');
// // });
// parser.on('data', data =>{
//   console.log('got word from arduino:', data);
// });


const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

const serialPort = new SerialPort('COM3', { baudRate: 9600 });
const serialParser = serialPort.pipe(new Readline({ delimiter: '\n' }));

// Read the serialPort data
serialPort.on("open", () => {
  console.log('serial serialPort open');
});

serialParser.on('data', data =>{
  console.log('got word from arduino:', data);
});

let angle = 0;
setInterval(() => {
    serialPort.write(`${angle}\n`, (err) => {
        if (err) {
          return console.log('Error on write: ', err.message);
        }
        console.log('message written');
    });
    
    angle += 10;
    
    if(angle > 180) {
        angle = 0;
    };
}, 1000);
