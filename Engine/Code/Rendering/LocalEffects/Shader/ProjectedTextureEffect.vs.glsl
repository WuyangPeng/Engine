uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
};

uniform ProjectorMatrix
{
    mat4 projectorMatrix;
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

layout(location = 0) in vec3 inModelPosition;
layout(location = 1) in vec3 inModelNormal;
layout(location = 0) out vec4 vertexColor;
layout(location = 1) out vec4 projectorTCoord;

void main()
{
    float NDotL = -dot(inModelNormal, lightModelDirection.xyz);
    vec3 viewVector = normalize(cameraModelPosition.xyz - inModelPosition);
    vec3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float NDotH = dot(inModelNormal, halfVector);
    vec4 lighting = lit(NDotL, NDotH, materialSpecular.a);
    
    vertexColor.rgb = materialEmissive.rgb + materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;
    vertexColor.a = materialDiffuse.a;
    
    vec4 modelPosition = vec4(inModelPosition, 1.0f);
 
    gl_Position = projectionViewWorldMatrix * modelPosition;
    projectorTCoord = projectorMatrix * modelPosition;
    
}