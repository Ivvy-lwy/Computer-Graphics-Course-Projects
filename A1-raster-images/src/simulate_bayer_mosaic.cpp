#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  int index;
  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  index = row * width + col;
		  if (row % 2 == 0) {
			  if (col % 2 == 0) {	// Assign green
				  bayer[index] = rgb[row * width * 3 + col * 3 + 1];
			  }
			  else {				// Assign blue
				  bayer[index] = rgb[row * width * 3 + col * 3 + 2];
			  }
		  }
		  else {
			  if (col % 2 == 0) {	// Assign red
				  bayer[index] = rgb[row * width * 3 + col * 3];
			  }
			  else {				// Assign green
				  bayer[index] = rgb[row * width * 3 + col * 3 + 1];
			  }
		  }
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
