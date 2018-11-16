#include <stdint.h>
#include "lm4f120h5qr.h"
 
#define LED_RED (1U << 1)  // which is the same as 00000010 in binary
#define LED_BLUE (1U << 2) // which is the same as 00000100 in binary
#define LED_GREEN (1U << 3)// which is the same as 00001000 in binary
#define LED_OFF (0U)        // which is the same as 00000000 in binary

void delay(int i);

int main() {
    
    // 1. Activating the Clock Gate
    //RCGCGPIO = 0x20U;
    // or using the file header
    SYSCTL_RCGCGPIO_R = (1U << 5);
    
    // 2. Choose the direction for three LEDs which means 3 bits
    // GPIO_DIR = 0x0EU;
    // or using the header 
    GPIO_PORTF_DIR_R |= (LED_RED|LED_BLUE|LED_GREEN);
    
    // 3. Digitize the output for all three pins
    // GPIO_DIG = 0x0EU;
    // or using the header file
    GPIO_PORTF_DEN_R  |= (LED_RED|LED_BLUE|LED_GREEN);

    GPIO_PORTF_DATA_R |= LED_BLUE;
   
    
    while(1){
      
       // Turn the red LED on
      GPIO_PORTF_DATA_R |= LED_RED;
      delay(1000000);
      GPIO_PORTF_DATA_R &= ~LED_RED;
    }

    return 0;
}
void delay(int i){
  
    /* In high optimization the loop probably would not run. In this case we
    use the key 'Volatile' to tell the compiler that do not jump over this 
    loop*/
    int volatile counter = 0;
    while(counter < i){
      ++ counter;
    }
}
