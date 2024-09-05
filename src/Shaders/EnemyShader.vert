#version 330 core

layout (location = 0) in vec4 vertex;

uniform mat4 instanceModel;
uniform mat4 projection; 

void main()
{
	TexCoords = vertex.zw;
	gl_Position = projection * instanceModel * vec4(vertex.xy,0.0,1.0);
}