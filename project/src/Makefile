# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink.elf 

#additional rules for files
blink.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o led.o p1_interrupt_handler.o wdInterruptHandler.o buzzer.o switches.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blink.elf
	msp430loader.sh blink.elf

clean:
	rm -f *.o *.elf *~

led.o:  led.h



wdInterruptHandler.o: stateMachines.h switches.h buzzer.h led.h

stateMachines.o: led.h stateMachines.h buzzer.h switches.h

buzzer.o: buzzer.h

switches.o: switches.h led.h buzzer.h stateMachines.h

p1_interrupt_handler.o: switches.h



