#include "kinematics_jacobian.h"
#include "transformed_tips.h"
#include <iostream>

void kinematics_jacobian(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  Eigen::MatrixXd & J)
{
  /////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < b.size() * 3; i++) {
		for (int j = 0; j < skeleton.size() * 3; j++) {
			
		}
	}
  J = Eigen::MatrixXd::Zero(b.size()*3,skeleton.size()*3);
  /////////////////////////////////////////////////////////////////////////////
}
