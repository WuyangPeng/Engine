struct PS_INPUT
{
    float4 vertexColor : COLOR;
    float4 projectorTCoord : TEXCOORD0;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET0;
};

Texture2D<float4> baseTexture;
SamplerState baseSampler;

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;
    float2 tcoord = input.projectorTCoord.xy / input.projectorTCoord.w;
    float4 baseColor = baseTexture.Sample(baseSampler, tcoord);
    output.pixelColor = baseColor * input.vertexColor;
    return output;
}