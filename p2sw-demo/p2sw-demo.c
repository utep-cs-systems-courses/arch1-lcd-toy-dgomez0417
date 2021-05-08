/** \file lcddemo.c
 *  \brief A simple demo that draws a string and circle
 */

#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>


/** Initializes everything, clears the screen, draws "hello" and the circle */
void main()
{
  configureClocks();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8);			/* GIE (enable interrupts) */
  u_char width = screenWidth, height = screenHeight;
 
  /*clearScreen(COLOR_BLUE);
  while (1) {
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
      clearScreen(COLOR_BLUE);
    }
  }*/ 
}


/*void switchesDiamond(){
  clearScreen(COLOR_BLUE);
  while (1) {
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
      clearScreen(COLOR_BLUE);
    }
  }
}*/
