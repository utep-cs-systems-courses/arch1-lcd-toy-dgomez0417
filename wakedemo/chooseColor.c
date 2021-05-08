#include "lcdutils.h"
#include "lcddraw.h"
#include "abCircle.h"
#include "wake.h"

u_int chooseColor(u_int color){
  if (color == COLOR_GREEN) return COLOR_PURPLE;
  else if (color == COLOR_PURPLE) return COLOR_TURQUOISE;
  else return COLOR_GREEN;
}
