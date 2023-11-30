#include "Sphere.h"
#include "Ray.h"
#include<cmath>
bool Sphere::intersect(
	const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
	////////////////////////////////////////////////////////////////////////////
	Eigen::Vector3d d = ray.direction;
	Eigen::Vector3d e = ray.origin;
	Eigen::Vector3d c = center;
	double r = radius;

	double term1 = -d.dot(e - c);
	double term2 = pow(d.dot(e - c), 2) - (d.dot(d)) * ((e - c).dot(e - c) - pow(r, 2));
	if (term2 < 0) {
		return false;
	}
	double term3 = d.dot(d);

	double res1 = (term1 + sqrt(term2)) / term3;
	double res2 = (term1 - sqrt(term2)) / term3;

	if (res1 < min_t && res2 < min_t) {
		return false;
	}
	else if (res1 >= min_t && res2 >= min_t) {
		t = std::min({ res1, res2 });
	}
	else if (res1 >= min_t) {
		t = res1;
	}
	else if (res2 >= min_t) {
		t = res2;
	}
	n = (e + t * d - c) / r;
	return true;
	////////////////////////////////////////////////////////////////////////////
}

