const { checkBTPedal } = require('bindings')('bt_hid_keyboard')

module.exports = {
    checkBTPedal: function() {
        return checkBTPedal();
    }
} 