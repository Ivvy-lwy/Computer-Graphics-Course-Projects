// Generate a pseudorandom unit 3D vector
// 
// Inputs:
//   seed  3D seed
// Returns psuedorandom, unit 3D vector drawn from uniform distribution over
// the unit sphere (assuming random2 is uniform over [0,1]²).
//
// expects: random2.glsl, PI.glsl
vec3 random_direction( vec3 seed)
{
  /////////////////////////////////////////////////////////////////////////////
  // Reference: https://mathworld.wolfram.com/SpherePointPicking.html
  vec2 angles = random2(seed);
  vec3 res = vec3(pow(1 - pow(cos(angles.x), 2), 0.5) * cos(angles.y),
				  pow(1 - pow(cos(angles.x), 2), 0.5) * sin(angles.y),
				  cos(angles.x));
  return res;
  /////////////////////////////////////////////////////////////////////////////
}
