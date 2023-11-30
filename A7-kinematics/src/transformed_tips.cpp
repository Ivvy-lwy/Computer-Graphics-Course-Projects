#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton, 
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////
	Eigen::VectorXd tip_pos = Eigen::VectorXd::Zero(3 * b.size());
	std::vector<Eigen::Affine3d, Eigen::aligned_allocator<Eigen::Affine3d> > T;
	forward_kinematics(skeleton, T);

	for (int i = 0; i < b.size(); i++) {
		int idx = b[i];
		Bone curr = skeleton[idx];

		// Tip position before transformation.
		Eigen::Vector4d prev_tip_pos;
		prev_tip_pos.matrix() << curr.length, 0, 0, 1;

		// Compose bone's T with its rest_T to get the transformation acting on 
		// the canonical bone.
		Eigen::Vector4d pos = curr.rest_T * T[idx] * prev_tip_pos;
		tip_pos[i * 3] = pos[0];
		tip_pos[i * 3 + 1] = pos[1];
		tip_pos[i * 3 + 2] = pos[2];
	}

	return tip_pos;
  /////////////////////////////////////////////////////////////////////////////
}
