#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


char music_switch;
static char led_state = 0;
void led_advance(){
  switch(led_state){
  case 0: red_on = 0; green_on = 0; led_state = 1; break;
  case 1: red_on = 0; green_on = 1; led_state = 2; break;
  case 2: red_on = 1; green_on = 0; led_state = 0; break;
  }
  led_changed = 1;
  led_update();
}
static char song_state = 0;
static int period = 0;
void song(){
  switch(song_state){
  case 0:period = 500; song_state =1;red_on = 1; green_on = 0; break;
  case 1:period = 300; song_state =2;red_on = 0; green_on = 1; break;
  case 2:period = 900; song_state =3;red_on = 0; green_on = 0; break;
  case 3:period = 800; song_state =4;red_on = 0; green_on = 0; break;
  case 4:period = 700; song_state =0;red_on = 0; green_on = 0; break;
    

  }
  buzzer_set_period(period);
  led_changed = 1;
  led_update();

}




