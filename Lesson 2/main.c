/* The step to blink the LED is consisting of 3 steps
    1. Enable the Clock gating
    2. Enable the pin direction
    3. Digitize the output
    4. Turn the LED on
*/
int main() {
    // Clock gate enabling
    /* The first step is to turn on the clock gate. This is done by
     looking in to the Datasheet and looking for 'Clock Gating' in
     the search function. You have to set some bits to 1 which in
     hexa decimal is going to be 20. You derefference the shit and
     set the value of it to 0x20U. you use U because the registers
     are in unsigned int.*/
    *((unsigned int *)0x400FE608U)=0x20U;
  
    /* Now avtivate the pin direction. You can find it under GPIO F 
    Direction which is given in Datasheet file.*/
    *((unsigned int *)0x40025400U)=0x0EU;
  
    /* Find the pins and activate the pins you want to show the
    LED on */
    *((unsigned int *)0x4002551CU)=0x0EU;
    
    /* Now you can turn on the lights. I couldn't find the adress
    of the LEDs in the datasheet but I know the address from earlier*/
    *((unsigned int *)0x400253FCU)=0x00U;
    
    /* You can use a while loop for turning on and off*/
    while(1){
      
      int i  = 0;
      while(i < 10000){
      *((unsigned int *)0x400253FCU)=0x02U;
      }
      
      i = 0;
      while(i < 10000){
        *((unsigned int *)0x400253FCU)=0x00U;
      }
      
    }
    
    
    
    return 0;
}
