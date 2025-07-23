uniform sampler2D imageSampler;

layout(location = 0) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
	pixelColor = texture(imageSampler, vertexTCoord);
}