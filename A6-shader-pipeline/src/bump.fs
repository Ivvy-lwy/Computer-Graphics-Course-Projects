// Set the pixel color using Blinn-Phong shading (e.g., with constant blue and
// gray material color) with a bumpy texture.
// 
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
//                     linearly interpolated from tessellation evaluation shader
//                     output
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
//               rgb color of this pixel
out vec3 color;
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  vec3 ka = is_moon ? vec3(0.3, 0.3, 0.3): vec3(0,0,0.3);
  vec3 kd = is_moon ? vec3(0.3, 0.3, 0.3): vec3(0.3, 0.3, 0.8);
  vec3 ks = vec3(1, 1, 1) * 0.5;
  float phong = 700;

  vec3 v = normalize(-view_pos_fs_in.xyz);

  // rotate the light 1 orbit per 8s
  vec4 light = view * vec4(cos(M_PI * animation_seconds / 4) * 2, 2, 2 * sin(M_PI * animation_seconds / 4), 1);
  vec3 l = normalize(light.xyz - view_pos_fs_in.xyz);

  vec3 new_pos = bump_position(is_moon, sphere_fs_in);
  vec3 T;
  vec3 B;
  float epsilon = 0.0001;
  tangent(normalize(normal_fs_in.xyz), T, B);
  vec3 n = cross((bump_position(is_moon, sphere_fs_in + epsilon * T) - new_pos) / epsilon,
				 (bump_position(is_moon, sphere_fs_in + epsilon * B) - new_pos) / epsilon);
  n = normalize(n);

  color = blinn_phong(ka, kd, ks, phong, n, v, l);
  /////////////////////////////////////////////////////////////////////////////
}
