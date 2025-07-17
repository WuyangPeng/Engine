cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

cbuffer ConstantColor
{
    float4 constantColor;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
};

struct VS_OUTPUT
{
    float4 vertexColor : COLOR0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));
    output.vertexColor = constantColor;
    return output;
}