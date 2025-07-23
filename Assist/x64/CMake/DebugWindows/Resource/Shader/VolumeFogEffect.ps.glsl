uniform sampler2D baseSampler;

layout(location = 0) in vec4 vertexColor;
layout(location = 1) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
    vec4 textureColor = texture(baseSampler, vertexTCoord);
    pixelColor.rgb = (1.0f - vertexColor.a) * textureColor.rgb + vertexColor.a * vertexColor.rgb;
    pixelColor.a = 1.0f;
}