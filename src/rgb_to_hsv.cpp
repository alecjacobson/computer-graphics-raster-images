#include "rgb_to_hsv.h"

#include <cmath>
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double M = std::max(r, std::max(g, b));
  double m = std::min(r, std::min(g, b));
  double C = M - m;

  if (C == 0.0){
    h = 0.0;
  }
  else if (M == r){
    h = (g - b) / C;
    h = std::fmod(h, 6);
    if (h < 0.0){
      h += 6.0;
    }
  }
  else if (M == g){
    h = (b - r) / C + 2.0;
  }
  else if (M == b){
    h = (r - g)/ C + 4.0;
  }

  h *= 60.0;
  v = M;

  if (v == 0.0){
    s = 0.0;
  }
  else{
    s = C / v;
  }
  ////////////////////////////////////////////////////////////////////////////
}
