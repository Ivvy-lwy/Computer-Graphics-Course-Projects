// Construct the model transformation matrix. The moon should orbit around the
// origin. The other object should stay still.
//
// Inputs:
//   is_moon  whether we're considering the moon
//   time  seconds on animation clock
// Returns affine model transformation as 4x4 matrix
//
// expects: identity, rotate_about_y, translate, PI
mat4 model(bool is_moon, float time)
{
  /////////////////////////////////////////////////////////////////////////////

  // If the object is not the moon, stay still.
  if (!is_moon) {
	return identity();
  }

  mat4 trans = identity();
  // If it is moon, shirnk the model by 70%
  trans = uniform_scale(0.3) * trans;

  // shift the model away from the origin by 2 units
  trans = transpose(translate(vec3(2, 0, 2))) * trans;

  // rotate around the origin(earth) at a frequency of 1 revolution per 4 seconds.
  trans = rotate_about_y(-M_PI * time / 2) * trans;

  return trans;  

  /////////////////////////////////////////////////////////////////////////////
}
