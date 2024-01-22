Texture2D<float> imageTexture;
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
    float gray = imageTexture.Sample(imageSampler, input.vertexTCoord);
    output.pixelColor = float4(gray, gray, gray, 1.0f);
    return output;
}