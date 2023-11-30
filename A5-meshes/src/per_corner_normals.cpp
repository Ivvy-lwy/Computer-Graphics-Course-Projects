#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>
#include "cmath"

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  double epsilon = cos(corner_threshold * M_PI / 180);

  Eigen::MatrixXi NF = Eigen::MatrixXd::Zero(F.rows(), 3);
  Eigen::MatrixXi V_neighbour = Eigen::MatrixXd::Zero(F.rows(), 3);
  std::vector<std::vector<int> > VF;
  vertex_triangle_adjacency(F, V.rows(), VF);

  for (int i = 0; i < F.rows(); i++) {
	  Eigen::RowVector3d NF = triangle_area_normal(V.row(F(i, 0)), V.row(F(i, 1)), V.row(F(i, 2)));

	  for (int j = 0; j < 3; j++) {
		  Eigen::RowVector3d normal(0, 0, 0);
		  for (int f = 0; f < VF[F(i, j)].size(); f++) {
			  int n_idx = VF[F(i, j)][f];
			  Eigen::RowVector3d NG = triangle_area_normal(V.row(F(n_idx, 0)), V.row(F(n_idx, 1)), V.row(F(n_idx, 2)));

			  if (NG.normalized().dot(NF.normalized()) > epsilon) {
				  normal += NG;
			  }
		  }
		  N.row(i * 3 + j) = normal.normalized();
	  }

  }
  ////////////////////////////////////////////////////////////////////////////
}
