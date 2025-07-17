uniform sampler2D baseSampler;

layout(location = 0) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
	pixelColor = texture(baseSampler, vertexTCoord);
}