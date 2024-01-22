cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

cbuffer ProjectorMatrix
{
    float4x4 projectorMatrix;
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
};

struct VS_OUTPUT
{
    float4 vertexColor : COLOR;
    float4 projectorTCoord : TEXCOORD0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    float NDotL = -dot(input.modelNormal, lightModelDirection.xyz);
    float3 viewVector = normalize(cameraModelPosition.xyz - input.modelPosition);
    float3 halfVector = normalize(viewVector - lightModelDirection.xyz);
    float NDotH = dot(input.modelNormal, halfVector);
    float4 lighting = lit(NDotL, NDotH, materialSpecular.a);

    output.vertexColor.rgb = materialEmissive.rgb + materialAmbient.rgb * lightingAmbient.rgb + lighting.y * materialDiffuse.rgb * lightingDiffuse.rgb + lighting.z * materialSpecular.rgb * lightingSpecular.rgb;
    output.vertexColor.a = materialDiffuse.a;

    float4 modelPosition = float4(input.modelPosition, 1.0f);

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));
    output.projectorTCoord = mul(projectorMatrix, modelPosition);

    return output;
}