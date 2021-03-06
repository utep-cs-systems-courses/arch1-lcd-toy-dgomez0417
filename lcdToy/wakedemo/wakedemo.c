#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

u_char helloCol = 10;       /* where drawn */
u_char nextHelloCol = 10;   /* where to draw next */
signed char helloVelocity = 1;   /* */


void wdt_c_handler()
{
  static int secCount = 0;
  static int dsecCount = 0;

  secCount ++;
  dsecCount ++;
  
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    redrawScreen = 1;
  }
  if (dsecCount == 25) { /*10x / sec*/
    dsecCount = 0;
    nextHelloCol += helloVelocity;
    if (nextHelloCol > 30 || nextHelloCol < 10) {   /* moved to far? */
      helloVelocity = -helloVelocity;                /* negate direction */
      nextHelloCol += helloVelocity;
    }
    redrawScreen = 1;
  }
}
  

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      drawString5x7(helloCol,20, "hello", COLOR_BLUE, COLOR_BLUE);
      drawString5x7(nextHelloCol,20, "hello", fontFgColor, COLOR_BLUE);
      helloCol = nextHelloCol;
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}

    
    



