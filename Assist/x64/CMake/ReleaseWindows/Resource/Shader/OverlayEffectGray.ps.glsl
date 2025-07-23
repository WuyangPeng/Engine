uniform sampler2D imageSampler;

layout(location = 0) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
    float gray = texture(imageSampler, vertexTCoord).r;
    pixelColor = vec4(gray, gray, gray, 1.0f);
}