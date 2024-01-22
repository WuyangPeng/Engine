vec4 Lit(float nDotL, float nDotH, float m)
{
    float ambient = 1.0;
    float diffuse = max(nDotL, 0.0);
    float specular = step(0.0, nDotL) * pow(max(nDotH, 0.0), m);
    return vec4(ambient, diffuse, specular, 1.0);
}

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
    
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 0) out vec4 pixelColor;
    
void main()
{
    vec3 normal = normalize(vertexNormal);
    float nDotL = -dot(normal, lightModelDirection.xyz);
    vec3 viewVector = normalize(cameraModelPosition.xyz - vertexPosition);
    vec3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float nDotH = dot(normal, halfVector);
    vec4 lighting = lit(nDotL, nDotH, materialSpecular.a);
    
    vec3 color = materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;
    
    pixelColor.rgb = materialEmissive.rgb + lightingAttenuation.w * color;
    pixelColor.a = materialDiffuse.a;

}