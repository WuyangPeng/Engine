Texture2D<float4> imageTexture;
SamplerState imageSampler;

struct PS_INPUT
{
    float2 vertexTCoord : TEXCOORD0;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET0;
};

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;
    output.pixelColor = imageTexture.Sample(imageSampler, input.vertexTCoord);
    return output;
}