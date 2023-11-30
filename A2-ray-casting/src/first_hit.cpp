#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
	int i = 0;
	double closest = std::numeric_limits<double>::infinity();
	Eigen::Vector3d normal;

	for (std::shared_ptr<Object> object : objects) {
		bool res = object->intersect(ray, min_t, t, normal);
		if (res && t < closest) {
			closest = t;
			n = normal;
			hit_id = i;
		}
		i++;
    }
	t = closest;
	if (!isinf(closest)) {
		return true;
	}
	return false;
  ////////////////////////////////////////////////////////////////////////////
}

