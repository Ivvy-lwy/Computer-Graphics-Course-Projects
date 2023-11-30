// Input:
//   N  3D unit normal vector
// Outputs:
//   T  3D unit tangent vector
//   B  3D unit bitangent vector
void tangent(in vec3 N, out vec3 T, out vec3 B)
{
  /////////////////////////////////////////////////////////////////////////////
  // Reference: https://stackoverflow.com/questions/5255806/how-to-calculate-tangent-and-binormal 
  vec3 t1 = cross(N, vec3(0, 0, 1));
  vec3 t2 = cross(N, vec3(0, 1, 0));
  if (length(t1) > length(t2)) {
	T = normalize(t1);
  }
  else {
	T = normalize(t2);
  }
  B = normalize(cross(N, T));
  /////////////////////////////////////////////////////////////////////////////
}
