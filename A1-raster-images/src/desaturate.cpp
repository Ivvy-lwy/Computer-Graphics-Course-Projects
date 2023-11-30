#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  double r = 0;
  double g = 0;
  double b = 0;
  double h = 0;
  double s = 0;
  double v = 0;

  for (int row = 0; row < height; row++) {
	  for (int col = 0; col < width; col++) {
		  int idx = row * width * 3 + col * 3;
		  r = rgb[idx];
		  g = rgb[idx + 1];
		  b = rgb[idx + 2];

		  rgb_to_hsv(r, g, b, h, s, v);

		  s = s * (1 - factor);

		  hsv_to_rgb(h, s, v, r, g, b);

		  desaturated[idx] = r;
		  desaturated[idx + 1] = g;
		  desaturated[idx + 2] = b;
	  }
  }

  ////////////////////////////////////////////////////////////////////////////
}
