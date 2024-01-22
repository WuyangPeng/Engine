cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float4 modelColor : COLOR0;
    float2 modelTCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
    float4 vertexColor : COLOR0;
    float2 vertexTCoord : TEXCOORD0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));

    output.vertexColor = input.modelColor;
    output.vertexTCoord = input.modelTCoord;
    return output;
}