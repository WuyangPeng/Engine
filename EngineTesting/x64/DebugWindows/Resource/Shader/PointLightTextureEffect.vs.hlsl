cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float3 modelNormal : NORMAL;
    float2 modelTCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
    float3 vertexPosition : TEXCOORD0;
    float3 vertexNormal : TEXCOORD1;
    float2 vertexTCoord : TEXCOORD2;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    output.vertexPosition = input.modelPosition;
    output.vertexNormal = input.modelNormal;
    output.vertexTCoord = input.modelTCoord;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));

    return output;
}