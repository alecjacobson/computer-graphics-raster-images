#include "hsv_to_rgb.h"

#include <cmath>
#include <algorithm>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double C = v * s;
  double h_ = h / 60.0;
  double X = C * (1 - std::fabs(std::fmod(h_, 2.0) - 1));
  if (0 <= h_ && h_ < 1){
    r = C;
    g = X; 
    b = 0.0;
  }
  else if(1 <= h_ && h_ < 2){
    r = X;
    g = C;
    b = 0.0;
  }
  else if(2 <= h_ && h_ < 3){
    r = 0.0;
    g = C;
    b = X;
  }
  else if(3 <= h_ && h_< 4){
    r = 0;
    g = X;
    b = C;
  }
  else if(4 <= h_ && h_ < 5){
    r = X;
    g = 0;
    b = C;
  }
  else if(5 <= h_ && h_ < 6){
    r = C;
    g = 0;
    b = X;
  }
  double m = v - C;
  r += m;
  g += m;
  b += m;
  ////////////////////////////////////////////////////////////////////////////
}
