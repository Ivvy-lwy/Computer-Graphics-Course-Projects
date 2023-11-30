#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  int pos = row * width * num_channels + col * num_channels;
		  for (int i = 0; i < num_channels; i++) {
			  int check = row * width * num_channels + (width - 1) * num_channels - pos % (width * num_channels) + i;
			  char test = reflected[pos + i];
			  reflected.at(pos + i) = input[check];
		  } 
		  
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
