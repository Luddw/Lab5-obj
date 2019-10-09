#shader vertex 
#version 430
layout(location=0) in vec3 pos;
layout(location=1) in vec2 uv;
layout(location=0) uniform mat4 mv;
layout(location=1) uniform mat4 proj;
layout(location=1) out vec2 UV;
void main()
{
	gl_Position = proj*mv*vec4(pos, 1);
	UV = uv;
};

#shader fragment
#version 430
layout(location=1) in vec2 UV;
uniform sampler2D text;
out vec4 Color;
void main()
{
	float mipmaplvl = 1.0f;
	Color = texture2D(text,UV,mipmaplvl);
};
