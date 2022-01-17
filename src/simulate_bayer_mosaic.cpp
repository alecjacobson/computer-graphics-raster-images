#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)){
        bayer[j * width + i] = rgb[(j * width + i) * 3 + 1];
      }
      else if (i % 2 != 0 && j % 2 == 0){
        bayer[j * width + i] = rgb[(j * width + i) * 3 + 2];
      }
      else if (i % 2 == 0 && j %2 != 0){
        bayer[j * width + i] = rgb[(j * width + i) * 3];
      }
      
    }
  }
}
