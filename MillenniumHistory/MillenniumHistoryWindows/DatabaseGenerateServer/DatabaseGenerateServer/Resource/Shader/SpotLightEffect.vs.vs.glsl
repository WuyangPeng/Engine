vec4 Lit(float nDotL, float nDotH, float m)
{
    float ambient = 1.0;
    float diffuse = max(nDotL, 0.0);
    float specular = step(0.0, nDotL) * pow(max(nDotH, 0.0), m);
    return vec4(ambient, diffuse, specular, 1.0);
}

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
    vec4 lightingSpotCutoff;
    vec4 lightingAttenuation;
};
    
uniform LightCameraGeometry
{
    vec4 lightModelPosition;
    vec4 lightModelDirection;
    vec4 cameraModelPosition;
};
    
layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;
layout(location = 0) out vec4 vertexColor;
    
void main()
{
    vec4 lighting;
    vec3 modelLightDiff = modelPosition - lightModelPosition.xyz;
    vec3 vertexDirection = normalize(modelLightDiff);
    float vertexCosAngle = dot(lightModelDirection.xyz, vertexDirection);
    if (vertexCosAngle >= lightingSpotCutoff.y)
    {
        float NDotL = -dot(modelNormal, vertexDirection);
        vec3 viewVector = normalize(cameraModelPosition.xyz - modelPosition);
        vec3 halfVector = normalize(viewVector - vertexDirection);
        float NDotH = dot(modelNormal, halfVector);
        lighting = lit(NDotL, NDotH, materialSpecular.a);
        lighting.w = pow(abs(vertexCosAngle), lightingSpotCutoff.w);
    }
    else
    {
        lighting = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    }
    
    float distance = length(modelLightDiff);
    float attenuation = lightingAttenuation.w / (lightingAttenuation.x + distance *  (lightingAttenuation.y + distance * lightingAttenuation.z));
    
    vec3 color = materialAmbient.rgb * lightingAmbient.rgb + lighting.w * (lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb);
    
    vertexColor.rgb = materialEmissive.rgb + attenuation * color;
    vertexColor.a = materialDiffuse.a;
     
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);
       
}