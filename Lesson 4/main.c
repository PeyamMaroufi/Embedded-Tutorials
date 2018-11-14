/* Macro can be anything as long as they make sense. You can add them together
   subtract them and so.*/

#define RCGCGPIO (*((unsigned int *) 0x400FE608U))
#define GPIOF_BASE 0x40025000U
#define GPIO_OFFSET_DIR 0x400U
#define GPIO_OFFSET_DIG 0x51CU
#define GPIO_LED_OFFSET 0x3FCU
#define GPIO_DIR (*((unsigned int *) (GPIOF_BASE + GPIO_OFFSET_DIR)))
#define GPIO_DIG (*((unsigned int *) (GPIOF_BASE + GPIO_OFFSET_DIG)))
#define GPIO_LED (*((unsigned int *) (GPIOF_BASE + GPIO_LED_OFFSET)))

void delay(int i);

int main() {
    
    // 1. Activating the Clock Gate
    RCGCGPIO = 0x20U;
    // 2. Choose the direction for three LEDs which means 3 bits
    GPIO_DIR = 0x0EU;
    // 3. Digitize the output for all three pins
    GPIO_DIG = 0x0EU;
    
    while(1){
      
        // Turn the red light on
      GPIO_LED= 0x02U;
      delay(1000000);
       // turn two LEDs
      GPIO_LED = 0x04U;
      delay(1000000);
       // turn three LEDs
      GPIO_LED= 0x06U;
      delay(1000000);
       // Turn off
      GPIO_LED = 0x00U;
      delay(1000000);
    }

    return 0;
}
void delay(int i){
    int counter = 0;
    while(counter < i){
      ++ counter;
    }
}
