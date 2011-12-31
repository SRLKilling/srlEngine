[Attrib]
vec2 inVertex
vec2 inTexcoord

[Output]
vec4 fragcolor;

[Vertex Shader]
out vec2 vertex;
out vec2 texcoord;

uniform mat4 srlProjectionMatrix;
uniform mat4 srlModelViewMatrix;

void main() {
	vertex = inVertex;
	texcoord = inTexcoord;
	gl_Position = srlProjectionMatrix * srlModelViewMatrix * vec4(inVertex, 1.0, 1.0);
}

[Fragment Shader]
in vec2 vertex;
in vec2 texcoord;

uniform sampler2D fontTex;

void main() {
	fragcolor = texture2D(fontTex, texcoord); //vec4(1.0, 1.0, 0.0, 1.0);
}