#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////
	// Lecture 7 slide p40.
	// Check whether there are at least two keyframes.
	if (keyframes.size() < 2) { return; }

	for (int i = 0; i < keyframes.size() - 1; i++) {
		double ti_1 = keyframes[i].first;
		double ti = keyframes[i + 1].first;

		// Check whether t is between these two frames.
		if (t > ti_1 && t < ti) {
			Eigen::Vector3d theta0, theta3;
			double t0, t3;
			if (i == 0) {
				theta0 = keyframes[0].second;
				t0 = keyframes[0].first;
			}
			else {
				theta0 = keyframes[i - 1].second;
				t0 = keyframes[i - 1].first;
			}

			Eigen::Vector3d theta1 = keyframes[i].second;
			double t1 = keyframes[i].first;

			Eigen::Vector3d theta2 = keyframes[i + 1].second;
			double t2 = keyframes[i + 1].first;

			if (i == keyframes.size() - 2) {
				theta3 = keyframes[i + 1].second;
				t3 = keyframes[i + 1].first;
			}
			else {
				theta3 = keyframes[i + 2].second;
				t3 = keyframes[i + 2].first;
			}

			Eigen::Vector3d m0 = (theta1 - theta0) / (t1 - t0);
			Eigen::Vector3d m1 = (theta2 - theta1) / (t2 - t1);

			double t = (t - t0) / (t1 - t0);
			return (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * theta0
				+ (pow(t, 3) - 2 * pow(t, 2) + t) * m0
				+ (-2 * pow(t, 3) + 3 * pow(t, 2)) * theta1
				+ (pow(t, 3) - pow(t, 2)) * m1;

		}
	}


  return Eigen::Vector3d(0,0,0);
  /////////////////////////////////////////////////////////////////////////////
}
