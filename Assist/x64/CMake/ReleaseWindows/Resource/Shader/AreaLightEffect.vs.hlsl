cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float2 modelTextureCoordinate : TEXCOORD0;
};

struct VS_OUTPUT
{
    float4 vertexPosition : TEXCOORD0;
    float2 vertexTextureCoordinate : TEXCOORD1;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;
    output.vertexPosition = float4(input.modelPosition, 1.0f);
    output.vertexTextureCoordinate = input.modelTextureCoordinate;

    output.clipPosition = mul(projectionViewWorldMatrix, output.vertexPosition);
    return output;
}