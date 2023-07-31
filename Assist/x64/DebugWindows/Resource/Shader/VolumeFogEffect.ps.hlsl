Texture2D baseTexture;
SamplerState baseSampler;

struct PS_INPUT
{
    float4 vertexColor : COLOR0;
    float2 vertexTCoord : TEXCOORD0;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET0;
};

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;
    float4 textureColor = baseTexture.Sample(baseSampler, input.vertexTCoord);
    output.pixelColor.rgb = (1.0f - input.vertexColor.a) * textureColor.rgb + input.vertexColor.a * input.vertexColor.rgb;
    output.pixelColor.a = 1.0f;
    return output;
}