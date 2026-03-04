/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void main()
{

    LED_Init(GPIO_PORTA, GPIO_PIN0);
    LED_Init(GPIO_PORTA, GPIO_PIN1);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1);

    while(1)
    {
        // if switch 1 is pressed, leds blink fast (short sequance)
        if(SWITCH_GetState(GPIO_PORTB, GPIO_PIN0) == SWITCH_PRESSED)
        {
            LED_On(GPIO_PORTA, GPIO_PIN0);
            LED_On(GPIO_PORTA, GPIO_PIN1);
            delay();
            LED_Off(GPIO_PORTA, GPIO_PIN0);
            LED_Off(GPIO_PORTA, GPIO_PIN1);
            delay();
        }
        // if switch 2 is pressed, leds blink slow (long sequance)
        else if(SWITCH_GetState(GPIO_PORTB, GPIO_PIN1) == SWITCH_PRESSED)
        {
            LED_On(GPIO_PORTA, GPIO_PIN0);
            LED_On(GPIO_PORTA, GPIO_PIN1);
            delay();
            delay();
            LED_Off(GPIO_PORTA, GPIO_PIN0);
            LED_Off(GPIO_PORTA, GPIO_PIN1);
            delay();
            delay();
        }
        // if no switch is pressed, both leds are off
        else
        {
            LED_Off(GPIO_PORTA, GPIO_PIN0);
            LED_Off(GPIO_PORTA, GPIO_PIN1);
        }
    }
}