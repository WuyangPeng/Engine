layout(location = 0) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

uniform sampler2D baseSampler;

void main()
{
    pixelColor = texture(baseSampler, vertexTCoord);
}