#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>
using namespace std;

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // reference: https://www.rapidtables.com/convert/color/rgb-to-hsv.html
	double rprime = r / 255;
	double gprime = g / 255;
	double bprime = b / 255;
	double M = max({ rprime, gprime, bprime });
	double m = min({ rprime, gprime, bprime });
	double c = M - m;
	v = M;

	// Saturation
	if (v != 0) {
		s = c / v;
	}
	else {
		s = 0;
	}

	// Hue
	if (c == 0) {
		h = 0;
	}
	else if (M == rprime) {
		h = 60 * fmod((gprime - bprime) / c, 6);
	}
	else if (M == gprime) {
		h = 60 * ((bprime - rprime) / c + 2);
	}
	else if (M == bprime) {
		h = 60 * ((rprime - gprime) / c + 4);
	}
  ////////////////////////////////////////////////////////////////////////////
}
