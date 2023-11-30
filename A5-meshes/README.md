# Meshes


## Tasks

### White list

You're encouraged to use `#include <Eigen/Geometry>` to compute the [cross
product](https://en.wikipedia.org/wiki/Cross_product) of two 3D vectors
`.cross`.

### Black list

This assignment uses [libigl](http://libigl.github.io) for mesh viewing. libigl
has many mesh processing functions implemented in C++, including some of the
functions assigned here. Do not copy or look at the following implementations:

`igl::per_vertex_normals`  
`igl::per_face_normals`  
`igl::per_corner_normals`  
`igl::double_area`  
`igl::vertex_triangle_adjacency`  
`igl::writeOBJ`  

### `src/write_obj.cpp`

Write a pure-triangle or pure-quad mesh with 3D vertex positions `V` and faces
`F`, 2D parametrization positions `UV` and faces `UF`, 3D normal vectors `NV`
and faces `NF` to a `.obj` file.

> **Note:** These _two_ function overloads represent only a small subset of
> meshes and mesh-data that can be written to a `.obj` file. 

### `src/cube.cpp`

Construct the quad mesh of a cube including parameterization and per-face
normals.

> **Hint:** Draw out on paper and _label_ with indices the 3D cube, the 2D
> parameterized cube, and the normals.

### `src/sphere.cpp`

Construct a quad mesh of a sphere with `num_faces_u` × `num_faces_v` faces.

### `src/triangle_area_normal.cpp`
Compute the normal vector of a 3D triangle given its corner locations. The
output vector should have length equal to the area of the triangle.

### `src/per_face_normals.cpp`
Compute per-face normals for a triangle mesh.

### `src/per_vertex_normals.cpp`
Compute per-vertex normals for a triangle mesh.

### `src/vertex_triangle_adjacency.cpp`
Compute a vertex-triangle adjacency list. For each vertex store a list of all
incident faces.

### `src/per_corner_normals.cpp`
Compute per corner normals for a triangle mesh by computing the area-weighted
average of normals at incident faces whose normals deviate less than the
provided threshold.

### `src/catmull_clark.cpp`

Conduct `num_iters` iterations of [Catmull-Clark
subdivision](https://en.wikipedia.org/wiki/Catmull–Clark_subdivision_surface) on
a **pure quad** mesh (`V`,`F`).

