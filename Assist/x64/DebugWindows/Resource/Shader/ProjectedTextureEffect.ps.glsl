layout(location = 0) in vec4 vertexColor;
layout(location = 1) in vec4 projectorTCoord;
layout(location = 0) out vec4 pixelColor;

uniform sampler2D baseSampler;

void main()
{
    vec2 tcoord = projectorTCoord.xy / projectorTCoord.w;
    vec4 baseColor = texture(baseSampler, tcoord);
    pixelColor = baseColor * vertexColor;
}