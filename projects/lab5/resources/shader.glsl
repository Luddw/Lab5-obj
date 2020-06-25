#shader vertex
#version 430
layout(location=0) in vec3 pos;
layout(location=1) in vec2 uv;
layout(location=2) in vec3 vert_normal;
layout(location=0) uniform mat4 m;
layout(location=1) uniform mat4 vp;
out vec3 fragment_pos;
out vec3 fragment_norm;
out vec2 UV;

void main()
{
	fragment_pos = vec3(m * vec4(pos , 1.0)); // world space vertex
	fragment_norm = inverse(transpose(mat3(m))) * vert_normal; // worldspace normal 
	gl_Position = vp*m*vec4(pos, 1); //vertex pos
	
	UV = uv;
};

#shader fragment
#version 430
layout(location=1) in vec2 UV;
uniform sampler2D text;
uniform vec4 lightcolor;
uniform vec4 lightpos; // the other objects color that is being lit by the lighting.
uniform vec4 intensity;
in vec3 fragment_pos;
in vec3 fragment_norm;
out vec4 Color;
void main()
{
	const float mipmaplvl = 1.0;
	vec3 textur = texture2D(text,UV,mipmaplvl).xyz;
	textur = vec3(1,1,1)*fragment_norm;
	
	//ambient
	vec3 ambient = intensity.x*lightcolor.xyz;
	//Color = vec4((lightcolor.xyz*textur) , 1.0);

	//vec3 ambient = intensity.x*lightcolor.xyz;
	//vec3 ambient = textur * intensity.x;
	//Color = vec4((ambient * textur).xyz, 1.0);
	//Color = vec4((ambient*lightcolor.xyz), 1.0);

	//diffuse
	vec3 norm = normalize(fragment_norm);
	vec3 lighting_direction = normalize(lightpos.xyz - fragment_pos);
	float diffuse_intensity = max(dot(norm, lighting_direction), 0.0);
	vec3 diffuse = diffuse_intensity * lightcolor.xyz;


	vec3 final = (ambient + diffuse) * textur;
	Color = vec4(final, 1.0);
/*
	vec3 norm = normalize(fragment_norm); // normalize the interpolated fragmentposition vectors to make sure they are unit vectors 100%.
	vec3 lighting_direction = normalize(lightpos.xyz - fragment_pos); //direction of the lighting
	float diffuse_intensity = max(dot(norm, lighting_direction), 0.0);
	vec3 diffuse = diffuse_intensity * lightcolor.xyz;
*/
	//vec3 lighting_final = (ambient  + diffuse) * textur;
	//Color = vec4(lighting_final, 1.0);

};
