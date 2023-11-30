#include "rgba_to_rgb.h"
#include <iostream>

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  int count1 = 1;
  int count2 = 0;
  for (char i : rgba) {
	  if (count1 % 4 != 0) {
		  rgb.at(count2) = i;
		  count2++;
	  }
	  count1++;
  }
  ////////////////////////////////////////////////////////////////////////////
}
