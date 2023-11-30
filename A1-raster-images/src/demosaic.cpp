#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  int index, r, g, b, numr, numg, numb, val;

  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  r = g = b = 0;
		  numr = numg = numb = 0;
		  for (int x = col - 1; x <= col + 1; x++) {
			  for (int y = row - 1; y <= row + 1; y++) {
				  index = y * width + x;
				  if (x >= 0 && y >= 0 && x < width && y < height) {
					  if (y % 2 == 0 && x % 2 == 1) {
						  b += bayer[index];
						  numb++;
					  }
					  else if (y % 2 == 1 && x % 2 == 0) {
						  r += bayer[index];
						  numr++;
					  }
					  else {
						  g += bayer[index];
						  numg++;
					  }

				  }
			  }
		  }

		  val = bayer[row * width + col];
		  if (row % 2 == 0 && col % 2 == 1) {
			  rgb[row * width * 3 + col * 3] = r / numr;
			  rgb[row * width * 3 + col * 3 + 1] = g / numg;
			  rgb[row * width * 3 + col * 3 + 2] = val;
		  }
		  else if (row % 2 == 1 && col % 2 == 0) {
			  rgb[row * width * 3 + col * 3] = val;
			  rgb[row * width * 3 + col * 3 + 1] = g / numg;
			  rgb[row * width * 3 + col * 3 + 2] = b / numb;
		  }
		  else {
			  rgb[row * width * 3 + col * 3] = r / numr;
			  rgb[row * width * 3 + col * 3 + 1] = val;
			  rgb[row * width * 3 + col * 3 + 2] = b / numb;
		  }
		  
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
