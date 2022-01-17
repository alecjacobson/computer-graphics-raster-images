#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < height * width; i++){
    double alpha_a = A[i * 4 + 3] / 255.0;
    double alpha_b = B[i * 4 + 3] / 255.0;
    double alpha_c = alpha_a + alpha_b * (1 - alpha_a);
    C[4 * i] = (A[4 * i] * alpha_a + B[4 * i] * alpha_b * (1 - alpha_a)) / alpha_c;
    C[4 * i + 1] = (A[4 * i + 1] * alpha_a + B[4 * i + 1] * alpha_b * (1 - alpha_a)) / alpha_c;
    C[4 * i + 2] = (A[4 * i + 2] * alpha_a + B[4 * i + 2] * alpha_b * (1 - alpha_a)) / alpha_c;
    C[4 * i + 3] = (int) alpha_c * 255;

  }
}
