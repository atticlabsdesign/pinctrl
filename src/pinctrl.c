#include "../pinctrl.h"


void setPin(pinId_t pinId, bool state){ //this feels like a clunky way of doing it
    if (state) {
        *pinId.port |= (1 << pinId.pin);
    } else {
        *pinId.port &= ~(1 << pinId.pin);
    }

    return;
}