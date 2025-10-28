#include "../pinctrl.h"


void setPin(pinId_t pinId, bool state){ //this feels like a clunky way of doing it
    if (state) {
        *pinId.portOut |= (1 << pinId.pin);
    } else {
        *pinId.portOut &= ~(1 << pinId.pin);
    }

    return;
}

bool getPin(pinId_t pinId){
    bool result = false;

    result = (*pinId.portIn & (1 << pinId.pin));

    return result; 
}