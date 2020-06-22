#shader vertex 
#version 430
layout(location=0) in vec3 pos;
layout(location=1) in vec2 uv;
layout(location=0) uniform mat4 m;
layout(location=1) uniform mat4 vp;
layout(location=1) out vec2 UV;
layout(location=2) in vec3 normal
out vec3 fragment_pos;
out vec3 fragment_norm;

void main()
{
	fragment_pos = vec3(m, vec4(pos,1.0)); // world space vertex
	fragment_normal = inverse(transpose(mat3(m))) * normal; // worldspace normal 

	gl_Position = vp*m*vec4(pos, 1); //vertex pos

	UV = uv;

};

#shader fragment
#version 430
layout(location=1) in vec2 UV;
uniform sampler2D text;
uniform vec3 lightcolor;
uniform vec3 lightpos;
uniform vec3 litcolor; // the other objects color that is being lit by the lighting.
uniform float intensity;
out vec4 Color;
void main()
{
	const float mipmaplvl = 1.0f;
	Color = texture2D(text,UV,mipmaplvl);
	Color = vec4((Color*lightcolor*intensity).xyz, 1.0);

	vec3 normal = normalize(normal); // normalize the interpolated fragmentposition vectors to make sure they are unit vectors 100%.
	vec3 lighting_direction = normalize(lightpos - fragment_pos); //direction of the lighting
	float diffuse_intensity = max(dot(normal, lighting_direction), 0.0);
	vec3 diffuse = diffuse_intensity * lightcolor;

	vec3 lighting_final = (Color.xyz  + diffuse ) * litcolor;
	Color = vec4(lighting_final, 1.0);

};
