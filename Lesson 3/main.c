/* We are trying to turn the LED on and off. For this we need to perform some steps
    1. We need to activate the Clock Gating. You can read and find Clock Gating
       in the Datasheet
    2. We need to choose the direction of the GPIO
    3. We need to set the GPIO as digital
    4. Turn the LED on 
    
   To know what port it is connected to you can find it in the scheme of the board
   which is available in the User Guide.
*/
int main() {
    
    // 1. Activating the Clock Gate
    *((unsigned int *) 0x400FE608U) = 0x20U;
    // 2. Choose the direction for three LEDs which means 3 bits
    *((unsigned int *) 0x40025400U) = 0x0EU;
    // 3. Digitize the output for all three pins
    *((unsigned int *) 0x4002551CU) = 0x0EU;
    
    while(1){
      
        // Turn the red light on
       *((unsigned int *) 0x400253FCU) = 0x02U;
       
       // Perform the Delay manually
       int counter = 0;
       while(counter < 1000000){
         ++ counter;
       }
       
       // turn two LEDs
       *((unsigned int *) 0x400253FCU) = 0x04U;
       
       counter = 0;
       while(counter < 1000000){
         ++ counter;
       }
       
       // turn three LEDs
      *((unsigned int *) 0x400253FCU) = 0x06U;
       
       counter = 0;
       while(counter < 1000000){
         ++ counter;
       }
       
       *((unsigned int *) 0x400253FCU) = 0x00U;
       
       counter = 0;
       while(counter < 1000000){
         ++ counter;
       }
    }

    return 0;
}
