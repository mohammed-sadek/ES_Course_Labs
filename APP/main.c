/*
* APPLICATION LAYER
*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/ext_int0_interface.h"

void App_Toggle_LED(void)
{
    LED_Toggle(GPIO_PORTA, GPIO_PIN0);
}

void main(void)
{
    LED_Init(GPIO_PORTA, GPIO_PIN0);

    EXT_INT0_Init();

    // Configure INT0 to trigger on the falling edge (button press)
    EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);

    // Tells the PIC which function to call when INT0 interrupt occurs
    EXT_INT0_SetCallback(App_Toggle_LED);

    // this enables INTE and GIE bits in INTCON register
    EXT_INT0_Enable();
    
    // Empty while loop to keep the main function running and allow interrupts to be handled
    while(1)
    {
        // Main loop can perform other tasks
    }
}