layout(location = 0) in vec3 emsAmbDifColor;
layout(location = 1) in vec3 spcColor;
layout(location = 2) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

uniform sampler2D baseSampler;

void main()
{
    vec4 baseColor = texture(baseSampler, vertexTCoord);
    pixelColor.rgb = baseColor.rgb * emsAmbDifColor + baseColor.a * spcColor;
    pixelColor.a = 1.0f;
}