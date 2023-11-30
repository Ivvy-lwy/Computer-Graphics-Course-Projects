// Create a bumpy surface by using procedural noise to generate a height (
// displacement in normal direction).
//
// Inputs:
//   is_moon  whether we're looking at the moon or centre planet
//   s  3D position of seed for noise generation
// Returns elevation adjust along normal (values between -0.1 and 0.1 are
//   reasonable.
float bump_height( bool is_moon, vec3 s)
{
  /////////////////////////////////////////////////////////////////////////////
  // Bump value
  float noise = improved_perlin_noise(s);
  // reference: textbook p277
  float bump = (1 + sin(30 * cos(noise) + 20 * sin(noise)) / 2) / 2;
  return bump;
  /////////////////////////////////////////////////////////////////////////////
}
