#include "fast_mass_springs_precomputation_sparse.h"
#include "signed_incidence_matrix_sparse.h"
#include <vector>

bool fast_mass_springs_precomputation_sparse(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXd & m,
  const Eigen::VectorXi & b,
  const double delta_t,
  Eigen::VectorXd & r,
  Eigen::SparseMatrix<double>  & M,
  Eigen::SparseMatrix<double>  & A,
  Eigen::SparseMatrix<double>  & C,
  Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > & prefactorization)
{
  /////////////////////////////////////////////////////////////////////////////
	// Construct r. #E list of edge lengths
	r.resize(E.rows());
	for (int i = 0; i < E.rows(); i++) {
		Eigen::Vector3d v1 = V.row(E(i, 0));
		Eigen::Vector3d v2 = V.row(E(i, 1));
		r(i) = (v1 - v2).norm();
	}

	// Construct M. M is a #V by #V diagonal matrix of masses.
	std::vector<Eigen::Triplet<double>> ijv;
	M.resize(V.rows(), V.rows());
	for (int j = 0; j < V.rows(); j++) {
		ijv.emplace_back(j, j, m(j));
	}
	M.setFromTriplets(ijv.begin(), ijv.end());

	// Construct A. #E by #V signed incidence matrix
	signed_incidence_matrix_sparse(V.rows(), E, A);

	// Construct C. #b by #V selection matrix.
	// C has one row per pinned vertex with a '+1' in the corresponding column.
	std::vector<Eigen::Triplet<double>> Cijv;
	C.resize(V.rows(), V.rows());
	for (int i = 0; i < b.rows(); i++) {
		Cijv.emplace_back(i, b(i), 1);
	}
	C.setFromTriplets(Cijv.begin(), Cijv.end());

	Eigen::SparseMatrix<double> Q = k * A.transpose() * A + M / pow(delta_t, 2);
	// quadratic energy term: w / 2 sum(||pi - pi_rest||^2) = 1 / 2 * tr(p^T(wC^TC)p)...
	// where w should be set to some large value. so we add wC^TC to Q.
	Q += 1e10 * C.transpose() * C;
  /////////////////////////////////////////////////////////////////////////////
  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
