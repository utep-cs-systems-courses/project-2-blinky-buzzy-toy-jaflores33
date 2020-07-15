#include <msp430.h>
#include "led.h"
#include "switches.h"

#include "buzzer.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void state_machine(char state){
 

    if(state == 1){
	buzzer_set_period(1000);
    }
    else if(state == 2){
      buzzer_set_period(1500);
    }
    else if(state == 3){
      buzzer_set_period(2000);
    }
    else if(state == 4){
      buzzer_set_period(2500);
    }
    else
      buzzer_set_period(0);
  
}

void led_update(){
  
  if (switch_state_changed) {

    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
    
    
  }//END_______
  
  switch_state_changed = 0;
}

