const { checkBTPedal, enumerate } = require('bindings')('bt_hid_keyboard')

module.exports = {
    checkBTPedal: function() {
        return checkBTPedal();
    },
    enumerateDevices: function() {
      return enumerate();
    }
} 