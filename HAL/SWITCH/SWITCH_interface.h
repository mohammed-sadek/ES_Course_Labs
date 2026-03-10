#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

// Switch states
#define SWITCH_PRESSED 0
#define SWITCH_RELEASED 1

// Switch initialization and state retrieval functions
void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_GetState(u8 Port, u8 Pin);


#endif