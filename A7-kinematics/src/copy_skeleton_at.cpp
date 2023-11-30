#include "copy_skeleton_at.h"
Skeleton copy_skeleton_at(
  const Skeleton & skeleton, 
  const Eigen::VectorXd & A)
{
  /////////////////////////////////////////////////////////////////////////////
	Skeleton copy = skeleton;
	for (int i = 0; i < copy.size(); i++) {
		Bone b = copy[i];
		b.xzx[0] = A[i * 3];
		b.xzx[1] = A[i * 3 + 1];
		b.xzx[2] = A[i * 3 + 1];
	}
  return copy;
  /////////////////////////////////////////////////////////////////////////////
}
