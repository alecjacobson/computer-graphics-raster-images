#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream output;
  output.open(filename);
  
  if (num_channels == 1){
    output << "P2" << std::endl;
    output << width << " " << height << std::endl << 255 << std::endl;
    for (int j = 0; j < height; j++){
      for (int i = 0; i < width; i++){
        output << (int)data[j * width + i] << " "; 
      }
      output << std::endl;
    }
  }
  else{
    output << "P3" << std::endl;
    output << width << " " << height << std::endl << 255 << std::endl;
    for (int i = 0; i < width * height; i++){
      output << (int)data[i * 3] << " " << (int)data[i * 3 + 1] << " "<< (int)data[i * 3 + 2] << std::endl;

    }
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
