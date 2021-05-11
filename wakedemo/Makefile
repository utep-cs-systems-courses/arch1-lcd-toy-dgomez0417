# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:wakedemo.elf

#additional rules for files
wakedemo.elf: ${COMMON_OBJECTS} chooseColorA.o jumpTable.o wakedemo.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lCircle -lp2sw 

wakedemo2.elf: ${COMMON_OBJECTS} chooseColorA.o  wakedemo.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: wakedemo.elf
	msp430loader.sh $^

load2: wakedemo2.elf
	msp430loader.sh $^

wakedemo.o: wakedemo.c wake.h

chooseColor.o: chooseColor.c wake.h

chooseColorA.o: chooseColorA.s wake.h

clean:
	rm -f *.o *.elf
