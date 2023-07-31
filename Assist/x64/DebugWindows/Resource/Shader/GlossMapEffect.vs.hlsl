cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

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

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float3 modelNormal : NORMAL;
    float2 modelTCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
    float3 emsAmbDifColor : COLOR;
    float3 spcColor : TEXCOORD0;
    float2 vertexTCoord : TEXCOORD1;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    float nDotL = -dot(input.modelNormal, lightModelDirection.xyz);
    float3 viewVector = normalize(cameraModelPosition.xyz - input.modelPosition);
    float3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float nDotH = dot(input.modelNormal, halfVector);
    float4 lighting = lit(nDotL, nDotH, materialSpecular.a);

    output.emsAmbDifColor = materialEmissive.rgb + materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb;

    output.spcColor = lighting.z * materialSpecular.rgb * lightingSpecular.rgb;

    output.vertexTCoord = input.modelTCoord;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));

    return output;
}