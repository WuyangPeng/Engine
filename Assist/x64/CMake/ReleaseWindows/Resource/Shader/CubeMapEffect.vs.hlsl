cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

cbuffer WorldMatrix
{
    float4x4 worldMatrix;
};

cbuffer CameraWorldPosition
{
    float4 cameraWorldPosition;
};

struct VS_INPUT
{
    float3 modelPosition : POSITION;
    float3 modelNormal : NORMAL;
    float4 modelColor : COLOR;
};

struct VS_OUTPUT
{
    float4 vertexColor : COLOR;
    float3 cubeTextureCoordinate : TEXCOORD0;
    float4 clipPosition : SV_POSITION;
};

VS_OUTPUT VSMain(VS_INPUT input)
{
    VS_OUTPUT output;

    float4 hModelPosition = float4(input.modelPosition, 1.0f);
    float3 worldPosition;
    float3 worldNormal;

    output.clipPosition = mul(projectionViewWorldMatrix, hModelPosition);
    worldPosition = mul(worldMatrix, hModelPosition).xyz;
    worldNormal = normalize(mul(worldMatrix, float4(input.modelNormal, 0.0f))).xyz;

    float3 eyeDirection = worldPosition - cameraWorldPosition.xyz;

    output.cubeTextureCoordinate = reflect(eyeDirection, worldNormal);

    output.vertexColor = input.modelColor;

    return output;
}