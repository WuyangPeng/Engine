cbuffer ProjectionViewWorldMatrix
{
    float4x4 projectionViewWorldMatrix;
};

cbuffer Material
{
    float4 materialEmissive;
    float4 materialAmbient;
};

cbuffer Light
{
    float4 lightingAmbient;
    float4 lightingAttenuation;
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

    float3 ambient = lightingAttenuation.w * lightingAmbient.rgb;
    output.vertexColor.rgb = materialEmissive.rgb + materialAmbient.rgb * ambient;
    output.vertexColor.a = 1.0f;

    output.clipPosition = mul(projectionViewWorldMatrix, float4(input.modelPosition, 1.0f));

    return output;
}