#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

// Register definitions for External Interrupt 0
#define INTCON (*((volatile u8*)0x0B))  // Interrupt Control Register
#define OPTION_REG (*((volatile u8*)0x81))

// Bit definitions for INTCON register
#define INTE 0  // External Interrupt 0 Enable
#define INTF 1  // External Interrupt 0 Flag
#define GIE 7   // Global Interrupt Enable

// Bit definitions for OPTION_REG register
#define INTEDG 6  // Interrupt Edge Select for INT0

#endif