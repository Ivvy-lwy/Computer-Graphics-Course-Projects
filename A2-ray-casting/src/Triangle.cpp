#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
	Eigen::Vector3d p1, p2, p3;
	p1 = std::get<0>(this->corners);
	p2 = std::get<1>(this->corners);
	p3 = std::get<2>(this->corners);

	double a, b, c, d, e, f, g, h, i, j, k, l;
	a = p1[0] - p2[0];
	b = p1[1] - p2[1];
	c = p1[2] - p2[2];
	d = p1[0] - p3[0];
	e = p1[1] - p3[1];
	f = p1[2] - p3[2];
	g = ray.direction[0];
	h = ray.direction[1];
	i = ray.direction[2];
	j = p1[0] - ray.origin[0];
	k = p1[1] - ray.origin[1];
	l = p1[2] - ray.origin[2];

	double ei_hf, gf_di, dh_eg, ak_jb, jc_al, bl_kc;
	ei_hf = e * i - h * f;
	gf_di = g * f - d * i;
	dh_eg = d * h - e * g;
	ak_jb = a * k - j * b;
	jc_al = j * c - a * l;
	bl_kc = b * l - k * c;

	double M, beta, gama;
	M = a * ei_hf + b * gf_di + c * dh_eg;
	t = -(f * ak_jb + e * jc_al + d * bl_kc) / M;
	if (t < min_t) {
		return false;
	}

	gama = (i * ak_jb + h * jc_al + g * bl_kc) / M;
	if (gama < 0 || gama > 1) {
		return false;
	}

	beta = (j * ei_hf + k * gf_di + l * dh_eg) / M;
	if (beta < 0 || beta > 1 - gama) {
		return false;
	}
	n = (p2 - p1).cross(p3 - p2);
	n = n.normalized();
	return true;
  ////////////////////////////////////////////////////////////////////////////
}


