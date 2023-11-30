#include "fast_mass_springs_step_sparse.h"
#include <igl/matlab_format.h>

void fast_mass_springs_step_sparse(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXi & b,
  const double delta_t,
  const Eigen::MatrixXd & fext,
  const Eigen::VectorXd & r,
  const Eigen::SparseMatrix<double>  & M,
  const Eigen::SparseMatrix<double>  & A,
  const Eigen::SparseMatrix<double>  & C,
  const Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > & prefactorization,
  const Eigen::MatrixXd & Uprev,
  const Eigen::MatrixXd & Ucur,
  Eigen::MatrixXd & Unext)
{
  //////////////////////////////////////////////////////////////////////////////
    // d contains the a vector representing the direction and length of rest length.
    Eigen::MatrixXd d = Eigen::MatrixXd::Zero(E.rows(), 3);
    Eigen::MatrixXd y = Eigen::MatrixXd::Zero(V.rows(), 3);
    y = M / pow(delta_t, 2) * (2 * Ucur - Uprev) + fext;

    Unext = Ucur;
    for (int iter = 0; iter < 50; iter++)
    {
        // The local step: hold y constant and optimize each spring vector d.
        for (int i = 0; i < E.rows(); i++) {
            Eigen::Vector3d v1 = Unext.row(E(i, 0));
            Eigen::Vector3d v2 = Unext.row(E(i, 1));
            d.row(i) = (v1 - v2).normalized() * r(i);
        }

        // The global step: minimize with respect to y
        Eigen::MatrixXd l = Eigen::MatrixXd::Zero(V.rows(), 3);
        l = k * A.transpose() * d + y + 1e10 * C.transpose() * C * V;
        Unext = prefactorization.solve(l);
    }
    //////////////////////////////////////////////////////////////////////////////
}
