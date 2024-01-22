uniform sampler3D baseSampler;

layout(location = 0) in vec3 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
    pixelColor = texture(baseSampler, vertexTCoord);
}