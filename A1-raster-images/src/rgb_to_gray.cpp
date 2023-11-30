#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  int idx, i, r, g, b;
  int num_channels = 3;
  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  idx = row * width * num_channels + col * num_channels;
		  i = 0.2126 * rgb[idx] + 0.7152 * rgb[idx + 1] + 0.0722 * rgb[idx + 2];
		  gray[row * width + col] = i;
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}


