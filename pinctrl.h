#ifndef PINCTRL_H
#define PINCTRL_H

#include <stdint.h>
#include <stdbool.h>

#define LOW     0 //might want to change this to an enum in case you want to set pin to tristate
#define HIGH    1

//im sure that there is a better way of doing this but this will do for now


typedef struct{ 
    volatile uint8_t *port;
    uint8_t pin;
} pinId_t;


/********************
---------------------
|  Public Functions |
---------------------
********************/


void setPin(pinId_t , bool );

#endif