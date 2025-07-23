cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float3 modelLightDirection : COLOR;
    float2 modelBaseTCoord : TEXCOORD0;
    float2 modelNormalTCoord : TEXCOORD1;
};

struct VS_OUTPUT
{
    float3 vertexLightDirection : COLOR;
    float2 vertexBaseTCoord : TEXCOORD0;
    float2 vertexNormalTCoord : TEXCORD1;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));

    output.vertexLightDirection = input.modelLightDirection;
    output.vertexBaseTCoord = input.modelBaseTCoord;
    output.vertexNormalTCoord = input.modelNormalTCoord;
    return output;
}