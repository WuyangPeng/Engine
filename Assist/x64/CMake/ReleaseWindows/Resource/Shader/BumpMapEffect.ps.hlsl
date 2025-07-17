Texture2D<float4> baseTexture;
SamplerState baseSampler;

Texture2D<float4> normalTexture;
SamplerState normalSampler;

struct PS_INPUT
{
    float3 vertexLightDirection : COLOR;
    float2 vertexBaseTextureCoordinate : TEXCOORD0;
    float2 vertexNormalTextureCoordinate : TEXCOORD1;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET;
};

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;
    float3 baseColor = baseTexture.Sample(baseSampler, input.vertexBaseTextureCoordinate).rgb;
    float3 normalColor = normalTexture.Sample(normalSampler, input.vertexNormalTextureCoordinate).rgb;
    float3 lightDirection = 2.0f * input.vertexLightDirection - 1.0f;
    float3 normalDirection = 2.0f * normalColor - 1.0f;
    lightDirection = normalize(lightDirection);
    normalDirection = normalize(normalDirection);
    float ldN = dot(lightDirection, normalDirection);
    ldN = saturate(ldN);
    output.pixelColor = float4(ldN * baseColor, 1.0f);
    return output;
}