#include "euler_angles_to_transform.h"
#include <math.h>

Eigen::Affine3d euler_angles_to_transform(
  const Eigen::Vector3d & xzx)
{
  /////////////////////////////////////////////////////////////////////////////
  // Bone.xzx is actually backwards(xzx(2) is the first angle to rotate by 
  // and xzx(0) is the last angle to rotate by.
  // Note that xzx is in degrees
    constexpr double pi = 3.14159265358979323846;
    double angle1 = xzx[2] * pi / 180;
    Eigen::Affine3d A;
    A.matrix() << 
        cos(angle1), -sin(angle1), 0, 0,
        sin(angle1), cos(angle1), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    double angle2 = xzx[1] * pi / 180;
    Eigen::Affine3d B;
    B.matrix() <<
        cos(angle2), 0, sin(angle2), 0,
        0, 1, 0, 0,
        -sin(angle2), 0, cos(angle2), 0,
        0, 0, 0, 1;

    double angle3 = xzx[0] * pi / 180;
    Eigen::Affine3d C;
    C.matrix() <<
        cos(angle3), -sin(angle3), 0, 0,
        sin(angle3), cos(angle3), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;
    return A * B * C;
  /////////////////////////////////////////////////////////////////////////////
}
