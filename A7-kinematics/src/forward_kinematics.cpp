#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function

void forward_kinematics(
  const Skeleton & skeleton,
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T)
{
  /////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < skeleton.size(); i++) {
        Bone curr_bone = skeleton[i];
        Eigen::Affine3d rotation = euler_angles_to_transform(curr_bone.xzx);
        Eigen::Affine3d rest_T = curr_bone.rest_T;
        T.resize(skeleton.size(), Eigen::Affine3d::Identity());

        // Root
        if (i == 0) {
            T[i] = rest_T * rotation * rest_T.inverse();
        }

        else {
            T[i] = T[curr_bone.parent_index] * rest_T * rotation * rest_T.inverse();
        }
    }

  /////////////////////////////////////////////////////////////////////////////
}
