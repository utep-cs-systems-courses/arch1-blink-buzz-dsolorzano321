//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


int main(void) {
  
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();
  switch_init();
  buzzer_init();
  led_init();
  /* enable periodic interrupt */
  buzzer_set_period(0);

  or_sr(0x18);		/* CPU off, GIE on */
}
