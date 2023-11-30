#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  int newx, newy, newidx, idx;
  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  for (int i = 0; i < num_channels; i++) {
			  newx = row;
			  newy = width - 1 - col;
			  newidx = newy * height * num_channels + newx * num_channels + i;
			  idx = row * width * num_channels + col * num_channels + i;
			  rotated[newidx] = input[idx];
		  }
	  }
  }
		  ////////////////////////////////////////////////////////////////////////////
}
