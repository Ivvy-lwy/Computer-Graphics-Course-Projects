#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
	double ia = 0.1;	// Ambient light intensity.
	Eigen::Vector3d result = Eigen::Vector3d(0, 0, 0);
	Material material = *objects[hit_id]->material;
	
	Eigen::Vector3d kd = material.kd;
	Eigen::Vector3d ks = material.ks;
	double phong_exponent = material.phong_exponent;
	result += (material.ka.array() * Eigen::Vector3d(ia, ia, ia).array()).matrix();

	Eigen::Vector3d hit_point = ray.origin + t * ray.direction;

	for (std::shared_ptr<Light> light : lights) {
		Ray findLight;
		findLight.origin = hit_point + 0.001 * n;
		double max_t;
		light->direction(findLight.origin, findLight.direction, max_t);

		int hit_id1;
		double t;
		Eigen::Vector3d n1;
		bool hit = first_hit(findLight, 0.001, objects, hit_id1, t, n1);

		// Check whether the light is blocked
		if (!hit || t >= max_t) {
			Eigen::Vector3d I = light->I;
			Eigen::Vector3d h = (findLight.direction - ray.direction.normalized()).normalized();

			result += (kd.array() * I.array()).matrix() * std::max(0.0, n.dot(findLight.direction));
			result += (ks.array() * I.array()).matrix() *
				std::pow(std::max(0.0, n.dot(h)), phong_exponent);
		}

	}

	return result;
  ////////////////////////////////////////////////////////////////////////////
}
