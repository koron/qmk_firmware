#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "split_util.h"
#include "matrix.h"
#include "keyboard.h"
#include "wait.h"
#include "split_scomm.h"

#ifndef SPLIT_USB_TIMEOUT
#    define SPLIT_USB_TIMEOUT 2000
#endif

#ifndef SPLIT_USB_TIMEOUT_POLL
#    define SPLIT_USB_TIMEOUT_POLL 10
#endif

volatile bool isLeftHand = true;

bool waitForUsb(void) {
    for (uint8_t i = 0; i < (SPLIT_USB_TIMEOUT / SPLIT_USB_TIMEOUT_POLL); i++) {
        // This will return true if a USB connection has been established
        if (UDADDR & _BV(ADDEN)) {
            return true;
        }
        wait_ms(SPLIT_USB_TIMEOUT_POLL);
    }

    // Avoid NO_USB_STARTUP_CHECK - Disable USB as the previous checks seem to enable it somehow
    (USBCON &= ~(_BV(USBE) | _BV(OTGPADE)));

    return false;
}


bool is_keyboard_left(void) {
#if defined(SPLIT_HAND_PIN)
    // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
#elif defined(MASTER_RIGHT)
    return !is_keyboard_master();
#endif

    return is_keyboard_master();
}

static void keyboard_master_setup(void) {
    serial_master_init();
}

static void keyboard_slave_setup(void) {
    serial_slave_init();
}

void split_keyboard_setup(void) {
   isLeftHand = is_keyboard_left();

   if (is_keyboard_master()) {
      keyboard_master_setup();
   } else {
      keyboard_slave_setup();
   }
   sei();
}
