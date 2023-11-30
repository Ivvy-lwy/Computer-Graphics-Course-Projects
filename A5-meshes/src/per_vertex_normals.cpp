#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < F.rows(); i++) {
	  Eigen::MatrixXi res = triangle_area_normal(V.row(F(i, 0)), V.row(F(i, 1)), V.row(F(i, 2)));
	  N.row(F(i, 0)) += res;
	  N.row(F(i, 1)) += res;
	  N.row(F(i, 2)) += res;
  }

  for (int i = 0; i < N.rows(); i++)
  {
	  N.row(i).normalized();
  }
  ////////////////////////////////////////////////////////////////////////////
}
