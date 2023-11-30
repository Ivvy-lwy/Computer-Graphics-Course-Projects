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
  // reference: https://en.wikipedia.org/wiki/Alpha_compositing

  int idx;
  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  idx = row * width * 4 + col * 4;
		  double alpha_A = A[idx + 3] / 255.0;
		  double alpha_B = B[idx + 3] / 255.0;
		  double alpha_C = alpha_A + alpha_B * (1 - alpha_A);

		  for (int i = 0; i < 3; i++) {			  
			  double val = (A[idx + i] * alpha_A + B[idx + i] * alpha_B * (1 - alpha_A)) / alpha_C;
			  C[idx + i] = val;
		  }
		  C[idx + 3] = alpha_C * 255.0;
	  }
  }


  ////////////////////////////////////////////////////////////////////////////
}
