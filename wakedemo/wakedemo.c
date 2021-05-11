#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "abCircle.h"
#include "wake.h"
#include "p2switches.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_TURQUOISE;

u_char WordCol = 10;       /* where drawn */
u_char nextWordCol = 10;   /* where to draw next */
signed char wordVelocity = 1;   /* */


void wdt_c_handler()
{
  static int secCount = 0;
  static int dsecCount = 0;

  secCount ++;
  dsecCount ++;
  
  if (secCount == 450) {		/* once/sec */
    secCount = 0;
    fontFgColor = chooseColor(fontFgColor);
    redrawScreen = 1;
  }
  if (dsecCount == 45) { /*10x / sec*/
    dsecCount = 0;
    nextWordCol += wordVelocity;
    if (nextWordCol > 30 || nextWordCol < 10) {   /* moved to far? */
      wordVelocity = -wordVelocity;                /* negate direction */
      nextWordCol += wordVelocity;
    }
    redrawScreen = 1;
  }
}
  
/*u_int chooseColor(u_int color){
  if (color == COLOR_TURQUOISE) return COLOR_PURPLE;
  else if (color == COLOR_PURPLE) return COLOR_VIOLET;
  else return COLOR_TURQUOISE;
  }*/

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  p2sw_init(15);
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLACK);
  while (1) {                   /* forever */
    switchesDiamond();
    
    if (redrawScreen) {
      redrawScreen = 0;
      drawString11x16(WordCol,10, "color game", COLOR_BLACK, COLOR_BLACK);
      drawString11x16(nextWordCol,10, "color game", chooseColor(fontFgColor), COLOR_BLACK);
      WordCol = nextWordCol;
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }

}
void switchesDiamond(){
    u_int switches = p2sw_read();
    char str[5];
 
    str[0] = (switches & (1<<0)) ? 0 :1;
    str[1] = (switches & (1<<1)) ? 0 :1;
    str[2] = (switches & (1<<2)) ? 0 :1;
    str[3] = (switches & (1<<3)) ? 0 :1;

    if (str[0]){
      makeDiamond();
    }
    else if(str[1]){
      makeDiamond1();
    }
    else if(str[2]){
      makeDiamond2();
    }
    else if(str[3]){
      makeDiamond3();
    }
    else{
      allShape();
      clearScreen(COLOR_BLACK);
     
    }
}
