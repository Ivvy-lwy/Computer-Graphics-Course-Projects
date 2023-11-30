#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
	Eigen::Vector3d d = ray.direction;
	Eigen::Vector3d e = ray.origin;
	Eigen::Vector3d p0 = point;
	n = normal;

	double term1 = -n.dot(e - p0);
	double term2 = n.dot(d);
	double res = term1 / term2;

	if (res >= min_t) {
		t = res;
		n = n.normalized();
		return true;
	}
	return false;
  
  ////////////////////////////////////////////////////////////////////////////
}

