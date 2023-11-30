#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // See .obj file definition https://www.cs.cmu.edu/~mbz/personal/graphics/obj.html
  std::ofstream file(filename);
  file.open(filename);
  if (file.fail()) {
      std::cout << "Fail to create file.";
      return false;
  }

  // Write coordnates of vertices V
  for (int v_idx = 0; v_idx < V.rows(); v_idx++) {
      file << "v " << V(v_idx, 0) << " " << V(v_idx, 1) << " " << V(v_idx, 2) << std::endl;
  }

  // Write texture coordinates UV
  for (int vt_idx = 0; vt_idx < UV.rows(); vt_idx++) {
      file << "vt " << UV(vt_idx, 0) << " " << UV(vt_idx, 1) << std::endl;
  }

  // Write vertex normal NV
  for (int vn_idx = 0; vn_idx < NV.rows(); vn_idx++) {
      file << "vn " << NV(vn_idx, 0) << " " << NV(vn_idx, 1) << std::endl;
  }

  // Write face
  for (int f_idx = 0; f_idx < F.rows(); f_idx++) {
      file << "f ";
      for (int i = 0; i < F.cols(); i++) {
           file << F(f_idx, i) + 1<< "/";
           file << UF(f_idx, i) + 1 << "/";
           file << NF(f_idx, i) + 1 << " ";
      }
      file << std::endl;
  }

  file.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
  return false;
}
