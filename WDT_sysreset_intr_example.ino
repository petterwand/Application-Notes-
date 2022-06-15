#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h

#define ms16  ((0 << WDP3) | (0 << WDP2) | ( 0 << WDP1) | (0 << WDP0))
#define ms32  ((0 << WDP3) | (0 << WDP2) | ( 0 << WDP1) | (1 << WDP0))
#define ms64  ((0 << WDP3) | (0 << WDP2) | ( 1 << WDP1) | (0 << WDP0))
#define s0125 ((0 << WDP3) | (0 << WDP2) | ( 1 << WDP1) | (1 << WDP0))
#define s025  ((0 << WDP3) | (1 << WDP2) | ( 0 << WDP1) | (0 << WDP0))
#define s05   ((0 << WDP3) | (1 << WDP2) | ( 0 << WDP1) | (1 << WDP0))
#define s1    ((0 << WDP3) | (1 << WDP2) | ( 1 << WDP1) | (0 << WDP0))
#define s2    ((0 << WDP3) | (1 << WDP2) | ( 1 << WDP1) | (1 << WDP0))
#define s4    ((1 << WDP3) | (0 << WDP2) | ( 0 << WDP1) | (0 << WDP0))
#define s8    ((1 << WDP3) | (0 << WDP2) | ( 0 << WDP1) | (1 << WDP0))


void WDT_sysreset_intr_enable(int prescaleLevel){
  cli();
  wdt_reset();
  WDTCSR |= ((1 << WDCE) |  (1 << WDIE) | (1 << WDE));
  WDTCSR = (1 << WDIE) | (1 << WDE) | prescaleLevel;
  sei();

}

void setup() {
  Serial.begin(9600);
  Serial.println("System start");
  WDT_sysreset_intr_enable(s4);
}



void loop() {
  
  while(1){
    /* Kommenter ut koden under og prøv deg frem med 
        forskjellige delays for å se om det blir gjennomført
        avbrudd og system resets */
        
    // _delay_ms(4300);
    // wdt_reset();
    
  }
}

ISR(WDT_vect){
  Serial.println("An Interrupt occured");
  
}