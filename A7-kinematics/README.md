# Computer Graphics – Kinematics

## Tasks

### White List

 - `Eigen::Affine3d`
 - [`Eigen::AngleAxis`](https://eigen.tuxfamily.org/dox/classEigen_1_1AngleAxis.html)
 - `#include <Eigen/Geometry>`
 - c++ lambda functions and capturing `#include <functional>`

### Black List

 - `igl::lbs`
 - `igl::forward_kinematics`

### `src/euler_angles_to_transform.cpp`

### `src/forward_kinematics.cpp`

### `src/transformed_tips.cpp`

### `src/catmull_rom_interpolation.cpp`

### `src/linear_blend_skinning.cpp`

### `src/copy_skeleton_at.cpp`

### `src/end_effectors_objective_and_gradient.cpp`

### `src/kinematics_jacobian.cpp`

### `src/projected_gradient_descent.cpp`

### `src/line_search.cpp`

[eulerangles]: https://en.wikipedia.org/wiki/Euler_angles

> ## Notes for TAs editing the README
>
> This README file is too complex for [texify](https://github.com/apps/texify) to render. Use [readme2tex](https://github.com/leegao/readme2tex) locally to render the TeX to SVGs.
>
> `python -m readme2tex --output README.md README.tex.md --nocdn`
> 
> `sed -i 's/invert_in_darkmode\"/invert_in_darkmode\&sanitize=true\"/g' README.md`
