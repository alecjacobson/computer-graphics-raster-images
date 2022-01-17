#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

#include <cmath>
#include <algorithm>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width * height; i ++){
    double h, s, v;
    double r = (double)rgb[i * 3] ;
    double g = (double)rgb[i * 3 + 1];
    double b = (double)rgb[i * 3 + 2];
    r /= 255.0;
    g /= 255.0;
    b /= 255.0;
    rgb_to_hsv(r, g, b, h, s, v);
    h += shift;
    h = std::fmod(h, 360.0);

    hsv_to_rgb(h, s, v, r, g, b);
    shifted[i * 3] = (int) (r * 255);
    shifted[i * 3 + 1] = (int) (g * 255);
    shifted[i * 3 + 2] = (int) (b * 255);
  }
}
