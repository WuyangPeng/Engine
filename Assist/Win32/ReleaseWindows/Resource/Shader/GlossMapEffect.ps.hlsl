struct PS_INPUT
{
    float3 emsAmbDifColor : COLOR;
    float3 spcColor : TEXCOORD0;
    float2 vertexTCoord : TEXCOORD1;
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

    float4 baseColor = baseTexture.Sample(baseSampler, input.vertexTCoord);
    output.pixelColor.rgb = baseColor.rgb * input.emsAmbDifColor + baseColor.a * input.spcColor;
    output.pixelColor.a = 1.0f;

    return output;
}