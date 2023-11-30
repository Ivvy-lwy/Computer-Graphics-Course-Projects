#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
   V.resize(8,3);
   F.resize(6,4);
   UV.resize(14,2);
   UF.resize(6,4);
   NV.resize(6,3);
   NF.resize(6,4);

   // Vector coordiantes
   V.row(0) = Eigen::Vector3d(0, 0, 0);
   V.row(1) = Eigen::Vector3d(1, 0, 0);
   V.row(2) = Eigen::Vector3d(1, 1, 0);
   V.row(3) = Eigen::Vector3d(0, 1, 0);
   V.row(4) = Eigen::Vector3d(0, 0, 1);
   V.row(5) = Eigen::Vector3d(1, 0, 1);
   V.row(6) = Eigen::Vector3d(1, 1, 1);
   V.row(7) = Eigen::Vector3d(0, 1, 1);

   // Face 
   F.row(0) = Eigen::Vector3d(0, 3, 2, 1);
   F.row(1) = Eigen::Vector3d(0, 1, 5, 4);
   F.row(2) = Eigen::Vector3d(1, 2, 6, 5);
   F.row(3) = Eigen::Vector3d(2, 3, 7, 6);
   F.row(4) = Eigen::Vector3d(0, 4, 7, 3);
   F.row(5) = Eigen::Vector3d(4, 5, 6, 7);

   // texture coordinates
   UV.row(0) = Eigen::Vector3d(1 / 4, 0);
   UV.row(1) = Eigen::Vector3d(1 / 2, 0);
   UV.row(2) = Eigen::Vector3d(0, 1 / 4);
   UV.row(3) = Eigen::Vector3d(1 / 4, 1 /4 );
   UV.row(4) = Eigen::Vector3d(1 / 2, 1 / 4);
   UV.row(5) = Eigen::Vector3d(3 / 4, 1 / 4);
   UV.row(6) = Eigen::Vector3d(1, 1 / 4);
   UV.row(7) = Eigen::Vector3d(0, 1 / 2);
   UV.row(8) = Eigen::Vector3d(1 / 4, 1 / 2);
   UV.row(9) = Eigen::Vector3d(1 / 2, 1 / 2);
   UV.row(10) = Eigen::Vector3d(3 / 4, 1 / 2);
   UV.row(11) = Eigen::Vector3d(1, 1 / 2);
   UV.row(12) = Eigen::Vector3d(1 / 4, 3 / 4);
   UV.row(13) = Eigen::Vector3d(1 / 2, 3 / 4);

   // Face indices to UV
   UF.row(0) = Eigen::Vector3d(8, 9, 4, 3);
   UF.row(1) = Eigen::Vector3d(8, 3, 2, 7);
   UF.row(2) = Eigen::Vector3d(3, 4, 1, 0);
   UF.row(3) = Eigen::Vector3d(4, 9, 10, 5);
   UF.row(4) = Eigen::Vector3d(8, 12, 13, 9);
   UF.row(5) = Eigen::Vector3d(11, 6, 5, 10);

   // Normal vectors
   NV.row(0) = Eigen::Vector3d(0, 0, -1);
   NV.row(1) = Eigen::Vector3d(0, -1, 0);
   NV.row(2) = Eigen::Vector3d(1, 0, 0);
   NV.row(3) = Eigen::Vector3d(0, 1, 0);
   NV.row(4) = Eigen::Vector3d(-1, 0, 0);
   NV.row(5) = Eigen::Vector3d(0, 0, 1);


   NF.row(0) = Eigen::Vector3d(0, 0, 0, 0);
   NF.row(0) = Eigen::Vector3d(1, 1, 1, 1);
   NF.row(0) = Eigen::Vector3d(2, 2, 2, 2);
   NF.row(0) = Eigen::Vector3d(3, 3, 3, 3);
   NF.row(0) = Eigen::Vector3d(4, 4, 4, 4);
   NF.row(0) = Eigen::Vector3d(5, 5, 5, 5);

   ////////////////////////////////////////////////////////////////////////////

}
