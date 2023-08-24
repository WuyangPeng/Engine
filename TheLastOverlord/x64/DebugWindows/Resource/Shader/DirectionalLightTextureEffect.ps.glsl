 uniform Material
 {
    vec4 materialEmissive;
    vec4 materialAmbient;
    vec4 materialDiffuse;
    vec4 materialSpecular;
};

uniform Lighting
{
    vec4 lightingAmbient;
    vec4 lightingDiffuse;
    vec4 lightingSpecular;
    vec4 lightingAttenuation;
};

uniform LightCameraGeometry
{
    vec4 lightModelDirection;
    vec4 cameraModelPosition;
};

uniform sampler2D baseSampler;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
    vec3 normal = normalize(vertexNormal);
    float nDotL = -dot(normal, lightModelDirection.xyz);
    vec3 viewVector = normalize(cameraModelPosition.xyz - vertexPosition);
    vec3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float nDotH = dot(normal, halfVector);
    vec4 lighting = lit(nDotL, nDotH, materialSpecular.a);
    vec3 lightingColor = materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;

    vec4 textureColor = texture(baseSampler, vertexTCoord);

    vec3 color = lightingColor * textureColor.rgb;
    pixelColor.rgb = materialEmissive.rgb + lightingAttenuation.w * color;
    pixelColor.a = materialDiffuse.a * textureColor.a;
}