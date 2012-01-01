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
	fragcolor = vec4(0.2, 0.0, 8.0, 1.0) * texture2D(fontTex, texcoord).x; //vec4(1.0, 1.0, 0.0, 1.0);
	// fragcolor = vec4(texcoord.s, 0.0, texcoord.t, 1.0);
}