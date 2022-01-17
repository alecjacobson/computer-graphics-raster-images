#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      gray[j * width + i] = (int)(0.2126 * rgb[(j * width + i) * 3] + 0.7152 * rgb[(j * width + i) * 3 + 1] + 0.0722 * rgb[(j * width + i) * 3 + 2]);
    }
  }
}


