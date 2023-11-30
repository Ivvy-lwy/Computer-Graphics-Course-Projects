#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
	if (num_recursive_calls > 5) {
		return false;
	}

	int hit_id;				// hit_id  index into objects of object with first hit
	double t;				// t  _parametric_ distance along ray so that ray.origin+t*ray.direction is the hit location
	Eigen::Vector3d n;		// n  surface normal at hit location
	double min_d = 0.00001;
	bool hit = first_hit(ray, min_t, objects, hit_id, t, n);

	if (hit) {
		rgb = Eigen::Vector3d(0, 0, 0);
		Eigen::Vector3d reflected_rgb = Eigen::Vector3d(0, 0, 0);

		Ray reflected;
		reflected.origin = ray.origin + t * ray.direction;
		reflected.direction = reflect(ray.direction, n.normalized());

		bool reflect_hit = raycolor(reflected, min_d, objects, lights, num_recursive_calls + 1, reflected_rgb);
		if (reflect_hit) {
			Eigen::Vector3d km = objects[hit_id]->material->km;
			rgb += (km.array() * reflected_rgb.array()).matrix();
		}
		rgb += blinn_phong_shading(ray, hit_id, t, n.normalized(), objects, lights);
	}
	return hit;
  ////////////////////////////////////////////////////////////////////////////
}
