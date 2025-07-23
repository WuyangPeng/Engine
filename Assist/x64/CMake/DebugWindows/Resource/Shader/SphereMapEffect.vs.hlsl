cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

cbuffer VWMatrix
{
    float4x4 vwMatrix;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float3 modelNormal : NORMAL;
};

struct VS_OUTPUT
{
    float2 vertexTCoord : TEXCOORD0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    float4 modelPosition = float4(input.modelPosition, 1.0f);
    float4 modelNormal = float4(input.modelNormal, 0.0f);

    float4 cameraSpacePosition = mul(vwMatrix, modelPosition);
    float3 cameraSpaceNormal = normalize(mul(vwMatrix, modelNormal).xyz);
    output.clipPosition = mul(projectionViewWorldMatrix, modelPosition);

    float3 eyeDirection = normalize(cameraSpacePosition.xyz);
    float3 r = reflect(eyeDirection, cameraSpaceNormal);

    float oneMRZ = 1.0f - r.z;
    float invLength = 1.0f / sqrt(r.x * r.x + r.y * r.y + oneMRZ * oneMRZ);
    output.vertexTCoord = 0.5f * (r.xy * invLength + 1.0f);

    return output;
}