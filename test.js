'use-strict'

const { checkBTPedal } = require('./index')

if (checkBTPedal()) {
    console.log('BT pedal found');
}