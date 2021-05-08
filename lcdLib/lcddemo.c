/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);

  drawString11x16(10,10, "color game", COLOR_GREEN, COLOR_BLACK);

  u_char offset_r = 80, offset_c = 60;

  for( int r = 0; r <= 30; r++){
    for (int c = 0; c <= 30-r; c++){
      drawPixel(offset_c - c, offset_r + r, COLOR_PURPLE);
      drawPixel(offset_c + c, offset_r + r, COLOR_PURPLE);
    }
  }
  
  for( int r = 0; r <= 30; r++){
    for (int c = 0; c <= 30-r; c++){
      drawPixel(offset_c + c, offset_r - r, COLOR_PURPLE);
      drawPixel(offset_c - c, offset_r - r, COLOR_PURPLE);
    }
  }
  
  /*for( int r = offset_r; r <= offset_r - 10; r++){
    for (int c = offset_c; c <= offset_c - 10; c++){
      drawPixel(offset_c + c, offset_r + r, COLOR_BLACK);
    }
  }*/
}
