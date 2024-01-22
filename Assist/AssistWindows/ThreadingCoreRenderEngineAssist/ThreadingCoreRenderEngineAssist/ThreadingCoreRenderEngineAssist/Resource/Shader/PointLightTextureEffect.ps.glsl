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
    vec4 lightModelPosition;
    vec4 cameraModelPosition;
};

uniform sampler2D baseSampler;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

void main()
{
    vec3 modelLightDiff = vertexPosition - lightModelPosition.xyz;
    vec3 vertexDirection = normalize(modelLightDiff);
    float nDotL = -dot(vertexNormal, vertexDirection);
    vec3 viewVector = normalize(cameraModelPosition.xyz - vertexPosition.xyz);
    vec3 halfVector = normalize(viewVector - vertexDirection);
    float NDotH = dot(vertexNormal, halfVector);
    vec4 lighting = lit(nDotL, NDotH, materialSpecular.a);
    vec3 lightingColor = materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;
    
    float distance = length(modelLightDiff);
    float attenuation = lightingAttenuation.w / (lightingAttenuation.x + distance * (lightingAttenuation.y + distance * lightingAttenuation.z));
    
    vec4 textureColor = texture(baseSampler, vertexTCoord);
    
    vec3 color = lightingColor * textureColor.rgb;
    pixelColor.rgb = materialEmissive.rgb + attenuation * color;
    pixelColor.a = materialDiffuse.a * textureColor.a;
}