#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
	double closest = std::numeric_limits<double>::infinity();
	Eigen::Vector3d normal;

	for (std::shared_ptr<Object> triangle : this->triangles) {
		bool res = triangle->intersect(ray, min_t, t, normal);
		if (res && t < closest) {
			closest = t;
			n = normal;
		}
	}
	t = closest;
	if (!isinf(closest)) {
		return true;
	}
	return false;
  ////////////////////////////////////////////////////////////////////////////
}



