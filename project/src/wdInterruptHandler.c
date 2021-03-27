#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"


char music_switch;
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char buzz_count = 0;
  if(++buzz_count == 75 && music_switch == 1){
    song();
    buzz_count = 0;
  
  }
  
  else if(music_switch == 2){
    buzzer_set_period(0);

  }
  
  }
