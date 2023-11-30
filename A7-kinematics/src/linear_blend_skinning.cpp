#include "linear_blend_skinning.h"

void linear_blend_skinning(
  const Eigen::MatrixXd & V,
  const Skeleton & skeleton,
  const std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T,
  const Eigen::MatrixXd & W,
  Eigen::MatrixXd & U)
{
  /////////////////////////////////////////////////////////////////////////////
	for (int j = 0; j < V.size() / 3; j++) {
		Eigen::MatrixXd vj = Eigen::MatrixXd(0, 0, 0);
		for (int i = 0; i < skeleton.size(); i++) {
			 vj += W[j, i] * T[i].matrix() * V[j, 0];			
		}
		U[j] = vj[0];
		U[j + 1] = vj[1];
		U[j + 2] = vj[2];
	}
  /////////////////////////////////////////////////////////////////////////////
}
