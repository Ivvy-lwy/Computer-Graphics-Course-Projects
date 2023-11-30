// Given a 3d position as a seed, compute an even smoother procedural noise
// value. "Improving Noise" [Perlin 2002].
//
// Inputs:
//   st  3D seed
// Values between  -½ and ½ ?
//
// expects: random_direction, improved_smooth_step
float improved_perlin_noise( vec3 st) 
{
  /////////////////////////////////////////////////////////////////////////////
  // Find the surrounding corners.
  float x0 = floor(st.x);
  float y0 = floor(st.y);
  float z0 = floor(st.z);
  float x1 = x0 + 1;
  float y1 = y0 + 1;
  float z1 = z0 + 1;

  vec3 corner0 = vec3(x0, y0, z0);
  vec3 corner1 = vec3(x0, y0, z1);
  vec3 corner2 = vec3(x0, y1, z0);
  vec3 corner3 = vec3(x0, y1, z1);
  vec3 corner4 = vec3(x1, y0, z0);
  vec3 corner5 = vec3(x1, y0, z1);
  vec3 corner6 = vec3(x1, y1, z0);
  vec3 corner7 = vec3(x1, y1, z1);

  // On each of the 8 unit coordinates, generate a pseudorandom gradient vector.
  vec3 rand_dir0 = random_direction(corner0);
  vec3 rand_dir1 = random_direction(corner1);
  vec3 rand_dir2 = random_direction(corner2);
  vec3 rand_dir3 = random_direction(corner3);
  vec3 rand_dir4 = random_direction(corner4);
  vec3 rand_dir5 = random_direction(corner5);
  vec3 rand_dir6 = random_direction(corner6);
  vec3 rand_dir7 = random_direction(corner7);

  // Take the dot product between the gradient vector and the distance vector.
  float prod0 = dot(rand_dir0, st - corner0);
  float prod1 = dot(rand_dir1, st - corner1);
  float prod2 = dot(rand_dir2, st - corner2);
  float prod3 = dot(rand_dir3, st - corner3);
  float prod4 = dot(rand_dir4, st - corner4);
  float prod5 = dot(rand_dir5, st - corner5);
  float prod6 = dot(rand_dir6, st - corner6);
  float prod7 = dot(rand_dir7, st - corner7);

  // f(x) = a0 + improved_smooth_step(x) * (a1 - a0), for value a0 at grid node 0 and value a1 at grid node1.
  vec3 smt = improved_smooth_step(st - corner0);

  // Interpolate between pairs of values:
  float temp0 = prod0 + smt.z * (prod1 - prod0);
  float temp1 = prod2 + smt.z * (prod3 - prod2);
  float temp2 = prod4 + smt.z * (prod5 - prod4);
  float temp3 = prod6 + smt.z * (prod7 - prod6);

  // Interpolate again:
  float temp4 = temp0 + smt.y * (temp1 - temp0);
  float temp5 = temp2 + smt.y * (temp3 - temp2);

  float res = temp4 + smt.x * (temp5 - temp4);

  return res;
  /////////////////////////////////////////////////////////////////////////////
}

