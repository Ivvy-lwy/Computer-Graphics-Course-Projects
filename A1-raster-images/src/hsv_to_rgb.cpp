#include "hsv_to_rgb.h"
#include <cmath>
using namespace std;

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // reference: https://www.rapidtables.com/convert/color/hsv-to-rgb.html
	double C = v * s;
	double X = C * (1 - abs(fmod(h / 60, 2) - 1));
	double m = v - C;

	double rprime = 0;
	double gprime = 0;
	double bprime = 0;

	if (0 <= h && h < 60) {
		rprime = C;
		gprime = X;
		bprime = 0;
	}
	else if (60 <= h && h < 120) {
		rprime = X;
		gprime = C;
		bprime = 0;
	}
	else if (120 <= h && h < 180) {
		rprime = 0;
		gprime = C;
		bprime = X;
	}
	else if (180 <= h && h < 240) {
		rprime = 0;
		gprime = X;
		bprime = C;
	}
	else if (240 <= h && h < 300) {
		rprime = X;
		gprime = 0;
		bprime = C;
	}
	else if (300 <= h && h < 360) {
		rprime = C;
		gprime = 0;
		bprime = X;
	}
	
	r = (rprime + m) * 255;
	g = (gprime + m) * 255;
	b = (bprime + m) * 255;
  ////////////////////////////////////////////////////////////////////////////
}
