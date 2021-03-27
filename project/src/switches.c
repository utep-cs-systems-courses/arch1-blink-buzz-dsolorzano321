#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char SS1, SS2, SS3, SS4;
char music_switch;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  SS1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  SS2 = (p2val & SW2) ? 0 : 1;
  SS3 = (p2val & SW3) ? 0 : 1;
  SS4 = (p2val & SW4) ? 0 : 1;
  // switch_state_changed = 1;
  // led_update();
  
  if(SS1){
    buzzer_set_period(1000);
    
  }
  
  if(SS2){
    buzzer_set_period(0);
  }
  if(SS3){
    music_switch = 1;
    
  }
  if(SS4){
    music_switch = 2;
    //  led_advance();
  }
  

  
}
