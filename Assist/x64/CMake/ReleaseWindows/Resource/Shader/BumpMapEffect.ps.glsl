uniform sampler2D baseSampler;
uniform sampler2D normalSampler;

layout(location = 0) in vec3 vertexLightDirection;
layout(location = 1) in vec2 vertexBaseTextureCoordinate;
layout(location = 2) in vec2 vertexNormalTextureCoordinate;
layout(location = 0) out vec4 pixelColor;

void main()
{
    vec3 baseColor = texture(baseSampler, vertexBaseTextureCoordinate).rgb;
    vec3 normalColor = texture(normalSampler, vertexNormalTextureCoordinate).rgb;
    vec3 lightDirection = 2.0f * vertexLightDirection - 1.0f;
    vec3 normalDirection = 2.0f * normalColor - 1.0f;
    lightDirection = normalize(lightDirection);
    normalDirection = normalize(normalDirection);
    float LdN = dot(lightDirection, normalDirection);
    ldN = clamp(LdN, 0.0f, 1.0f);
    pixelColor = vec4(ldN * baseColor, 1.0f);
}