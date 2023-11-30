// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
out vec3 color;
// expects: PI, blinn_phong
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

  color = blinn_phong(ka, kd, ks, phong, normalize(normal_fs_in.xyz), v, l);
  /////////////////////////////////////////////////////////////////////////////
}
