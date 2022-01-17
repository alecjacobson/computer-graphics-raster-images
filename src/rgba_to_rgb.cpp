#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int j = 0; j < height; j++){
    for (int i = 0; i < width; i++){
      for (int k = 0; k < 4; k++) {
        rgb[(j * width + i) * 3 + k] = rgba[(j * width + i) * 4 + k];
      }
    }
  }
  

}
