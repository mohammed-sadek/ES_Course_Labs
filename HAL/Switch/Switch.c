#include "Switch_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void SWITCH_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 Port, u8 Pin)
{
    u8 PinState = GPIO_GetPinValue(Port, Pin);
    if (PinState == GPIO_LOW) // Assuming active low switch pull up configuration
        return SWITCH_PRESSED; // Switch is pressed
    else
        return SWITCH_RELEASED; // Switch is not pressed
}