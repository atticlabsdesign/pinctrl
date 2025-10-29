#include "../pinctrl.h"
#include <stdint.h>


void setPin8(pinId8_t pinId, bool state){ //this feels like a clunky way of doing it
    if (state) {
        *pinId.portOut |= (1 << pinId.pin);
    } else {
        *pinId.portOut &= ~(1 << pinId.pin);
    }

    return;
}

void setGroup8(pinGroup8_t group, uint8_t value){ 
    uint8_t nextVal = *group.portOut;
    value &= (0xFF >> (8-group.groupSize)); //should cut val to only be the number of bits as there are pins in the group just in case

    uint8_t msbPos = 1<< (group.groupSize-1);

    for (uint8_t i=0; i<group.groupSize; i++) {
        nextVal = (nextVal & ~(0xFF & (1 << group.pins[i]))) | (value & msbPos); //clear the value at the pin and then set it 
        value <<= 1;
    
    }

    *group.portOut = nextVal;

    return;
}

uint8_t getGroup8(pinGroup8_t group){ 
    uint8_t value = 0;
    uint8_t portVal = *group.portIn;

    uint8_t msbPos = 1<< (group.groupSize-1);

    for (uint8_t i=0; i<group.groupSize; i++) {
        value <<= 1;
        value = ((portVal >> group.pins[i]) & 1);
    
    }


    return value;
}

bool getPin8(pinId8_t pinId){
    bool result = false;

    result = (*pinId.portIn & (1 << pinId.pin));

    return result; 
}