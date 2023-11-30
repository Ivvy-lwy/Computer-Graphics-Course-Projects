# Ray Tracing

## Tasks

### `src/Plane.cpp`,<br> `src/Sphere.cpp`,<br> `src/Triangle.cpp`,<br> `src/TriangleSoup.cpp`,<br> `src/first_hit.cpp`,<br> `src/viewing_ray.cpp`,<br> `src/write_ppm.cpp`

See the previous [ray casting
assignment](https://github.com/alecjacobson/computer-graphics-ray-casting).

### `PointLight::direction` in `src/PointLight.cpp`

Compute the direction to a point light source and its _parametric_ distance from
a query point.

### `DirectionalLight::direction` in `src/DirectionalLight.cpp`

Compute the direction to a direction light source and its _parametric_ distance from a
query point (infinity).

### `src/raycolor.cpp`

Make use of `first_hit.cpp` to shoot a ray into the scene, collect hit
information and use this to return a color value. 

### `src/blinn_phong_shading.cpp`

Compute the lit color of a hit object in the scene using [Blinn-Phong shading
model](https://en.wikipedia.org/wiki/Blinn–Phong_shading_model). This function
should also shoot an additional ray to each light source to check for shadows.

![It is recommended to add and debug each term in your shading model. The
ambient term will look like a faint object-ID image. The diffuse term will
illuminate the scene, and create a dull, Lambertian look to each object. The
specular term will add shiny highlights. Then, mask the diffuse and specular
terms by checking for shadows. Finally, add a recursive call to account for
mirror reflections.](images/sphere-and-plane.gif)

### `src/reflect.cpp`

Given an "incoming" vector and a normal vector, compute the mirror reflected
"outgoing" vector.

![`./raytracing ../data/sphere-packing.json` should produce this
image of highly reflective, metallic looking
surfaces.](images/sphere-packing.png)

### `src/creative.json`

Be creative! Design a scene using any of the available Object types (spheres,
planes, triangles, triangle soups), Light types (directional, point), Material
parameters, colors (materials and/or lights), and don't forget about the camera
parameters.

The [.json format](https://en.wikipedia.org/wiki/JSON) is rather
straightforward. But you may find this [validator](https://jsonlint.com) useful.

