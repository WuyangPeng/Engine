cbuffer Translate
{
    float3 translate;
};
struct VS_INPUT
{
    float2 modelPosition : POSITION;
    float2 modelTCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
    float2 vertexTCoord : TEXCOORD0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;
    output.vertexTCoord = input.modelTCoord;
    output.clipPosition.x = 2.0f * input.modelPosition.x - 1.0f + 2.0f * translate.x;
    output.clipPosition.y = 2.0f * input.modelPosition.y - 1.0f + 2.0f * translate.y;
    output.clipPosition.z = translate.z;
    output.clipPosition.w = 1.0f;
    return output;
}