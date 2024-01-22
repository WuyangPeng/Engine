uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
};

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

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;
layout(location = 2) in vec2 modelTCoord;
layout(location = 0) out vec3 emsAmbDifColor;
layout(location = 1) out vec3 spcColor;
layout(location = 2) out vec2 vertexTCoord;

void main()
{
    float nDotL = -dot(modelNormal, lightModelDirection.xyz);
    vec3 viewVector = normalize(cameraModelPosition.xyz - modelPosition);
    vec3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float nDotH = dot(modelNormal, halfVector);
    vec4 lighting = lit(nDotL, nDotH, materialSpecular.a);

    emsAmbDifColor = materialEmissive.rgb + materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb;

    spcColor = lighting.z * materialSpecular.rgb * lightingSpecular.rgb;

    vertexTCoord = modelTCoord;
 
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f); 
}