#ifndef PINCTRL_H
#define PINCTRL_H

#include <stdint.h>
#include <stdbool.h>

#define LOW     0 //might want to change this to an enum in case you want to set pin to tristate
#define HIGH    1

//im sure that there is a better way of doing this but this will do for now


typedef struct{ 
    volatile uint8_t *portOut;
    volatile uint8_t *ddr;
    volatile uint8_t *portIn;
    uint8_t pin;
} pinId8_t;

typedef struct{
    volatile uint8_t *portOut;
    volatile uint8_t *ddr;
    volatile uint8_t *portIn;
    uint8_t groupSize;
    uint8_t pins[]; //msb is 0th element
} pinGroup8_t;

/********************
---------------------
|  Public Functions |
---------------------
********************/


void setPin8(pinId8_t , bool ); //if there is a way for the preprocessor to check the device architecture the 8 can be removed and we can "overload" the functions with preprocessor directives
bool getPin8(pinId8_t);
void setGroup8(pinGroup8_t pinId, uint8_t value);
uint8_t getGroup8(pinGroup8_t);

#endif