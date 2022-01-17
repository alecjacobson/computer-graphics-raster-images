#include "demosaic.h"
#include <cstdio>

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int j = 0; j < height; j++){
    for(int i = 0; i < width; i++){

      if (i % 2 == 0 && j % 2 == 0){      // top left green
          rgb[(j * width + i) * 3 + 1] = bayer[j * width + i];

        if (i == 0 && j == 0){
          rgb[(j * width + i) * 3 + 2] = bayer[j * width + i + 1];
          rgb[(j * width + i) * 3] = bayer[(j + 1) * width + i];
        }

        else if (j == 0){
          if (i == width - 1){
            rgb[(j * width + i) * 3 + 2] = bayer[j * width + i - 1];
          }
          else{
            rgb[(j * width + i) * 3 + 2] = (bayer[j * width + i - 1] + bayer[j * width + i + 1]) / 2;
          }
          rgb[(j * width + i) * 3] = bayer[(j + 1) * width + i];
        }

        else if (j == height - 1){
          if (i == 0){
            rgb[(j * width + i) * 3 + 2] = bayer[j * width + i + 1];
          }
          else if (i == width - 1){
            rgb[(j * width + i) * 3 + 2] = bayer[j * width + i - 1];
          }
          else{
            rgb[(j * width + i) * 3 + 2] = (bayer[j * width + i - 1] + bayer[j * width + i + 1]) / 2;
          }
          rgb[(j * width + i) * 3] = bayer[(j - 1) * width + i];
        }

        else if (i == 0){
          rgb[(j * width + i) * 3 + 2] = bayer[j * width + i + 1];
          rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 2;
        }

        else if (i == width - 1){
          rgb[(j * width + i) * 3 + 2] = bayer[j * width + i - 1];
          rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 2;
        }

        else{
          rgb[(j * width + i) * 3 + 2] = (bayer[j * width + i - 1] + bayer[j * width + i + 1]) / 2;

          rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 2;
        }
      }

      else if (i % 2 != 0 && j % 2 == 0){       // blue
        rgb[(j * width + i) * 3 + 2] = bayer[j * width + i];

        if (j == 0){
          if (i == width - 1){
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j + 1) * width + i]) / 2;
            rgb[(j * width + i) * 3] = bayer[(j + 1) * width + i - 1];
          }
          else {
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j + 1) * width + i] + bayer[j * width + i + 1]) / 3;

            rgb[(j * width + i) * 3] = (bayer[(j + 1) * width + i - 1] + bayer[(j + 1) * width + i + 1]) / 2;
          }
        }

        else if (j == height - 1){
          if (i == width - 1){
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i]) / 2;
            rgb[(j * width + i) * 3] = bayer[(j - 1) * width + i - 1];
          }
          else{
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[j * width + i + 1]) / 3;

            rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i - 1] + bayer[(j - 1) * width + i + 1]) / 2;
          }
        }

        else if (i == width - 1){
          rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 3;

          rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i - 1] + bayer[(j + 1) * width + i - 1]) / 2;
        }
        
        else{
          rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i] + bayer[j * width + i + 1]) / 4;

          rgb[(j * width + i) * 3] = (bayer[(j - 1) * width + i - 1] + bayer[(j + 1) * width + i - 1] + bayer[(j - 1) * width + i + 1] + bayer[(j + 1) * width + i + 1]) / 4;
        }
      }

      else if (i % 2 == 0 && j % 2 != 0) {          //  red
        rgb[(j * width + i) * 3] = bayer[j * width + i];

        if (i == 0){
          if (j == height - 1){
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i + 1] + bayer[(j - 1) * width + i]) / 2;

            rgb[(j * width + i) * 3 + 2] = bayer[(j - 1) * width + i + 1];
          }
          else {
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i + 1] + bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 3;

            rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i + 1] + bayer[(j + 1) * width + i + 1]) / 2;
          }
        }

        else if (i == width - 1){
          if (j == height - 1){
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i]) / 2;

            rgb[(j * width + i) * 3 + 2] = bayer[(j - 1) * width + i - 1];
          }
          else{
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 3;

            rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i - 1] + bayer[(j + 1) * width + i - 1]) / 2;
          }
        }

        else if (j == height - 1){
            rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[j * width + i + 1]) / 3;

            rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i - 1] + bayer[(j - 1) * width + i + 1]) / 2;
        }

        else{
          rgb[(j * width + i) * 3 + 1] = (bayer[j * width + i - 1] + bayer[(j - 1) * width + i] + bayer[j * width + i + 1] + bayer[(j + 1) * width + i]) / 4;

          rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i - 1] + bayer[(j - 1) * width + i + 1] + bayer[(j + 1) * width + i - 1] + bayer[(j + 1) * width + i + 1]) / 4;
        }
      }

      else{               // bottom right green
        rgb[(j * width + i) * 3 + 1] = bayer[j * width + i];

        if (i == width - 1){
          if (j == height - 1){
            rgb[(j * width + i) * 3 + 2] = bayer[(j - 1) * width + i];
            rgb[(j * width + i) * 3] = bayer[j * width + i - 1];
          }
          else{
            rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 2;
            rgb[(j * width + i) * 3] = bayer[j * width + i - 1];
          }
        }

        else if (j == height - 1){
          rgb[(j * width + i) * 3 + 2] = bayer[(j - 1) * width + i];
          rgb[(j * width + i) * 3] = (bayer[j * width + i - 1] + bayer[j * width + i + 1]) / 2;
        }

        else {
          rgb[(j * width + i) * 3 + 2] = (bayer[(j - 1) * width + i] + bayer[(j + 1) * width + i]) / 2;

          rgb[(j * width + i) * 3] = (bayer[j * width + i - 1] + bayer[j* width + i + 1]) / 2;
        }
      }

        
        

    }


  }

}
