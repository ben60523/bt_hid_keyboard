'use-strict'

const { checkBTPedal, enumerateDevices } = require('./index')

enumerateDevices();

if (checkBTPedal()) {
    console.log('BT pedal found');
}