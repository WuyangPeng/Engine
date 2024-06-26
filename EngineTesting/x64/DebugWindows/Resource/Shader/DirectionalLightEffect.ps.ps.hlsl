cbuffer Material
{
    float4 materialEmissive;
    float4 materialAmbient;
    float4 materialDiffuse;
    float4 materialSpecular;
};

cbuffer Lighting
{
    float4 lightingAmbient;
    float4 lightingDiffuse;
    float4 lightingSpecular;
    float4 lightingAttenuation;
};

cbuffer LightCameraGeometry
{
    float4 lightModelDirection;
    float4 cameraModelPosition;
};

struct PS_INPUT
{
    float3 vertexPosition : TEXCOORD0;
    float3 vertexNormal : TEXCOORD1;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET0;
};

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;

    float3 normal = normalize(input.vertexNormal);
    float nDotL = -dot(normal, lightModelDirection.xyz);
    float3 viewVector = normalize(cameraModelPosition.xyz - input.vertexPosition);
    float3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float nDotH = dot(normal, halfVector);
    float4 lighting = lit(nDotL, nDotH, materialSpecular.a);

    float3 color = materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;

    output.pixelColor.rgb = materialEmissive.rgb + lightingAttenuation.w * color;
    output.pixelColor.a = materialDiffuse.a;
    return output;
}