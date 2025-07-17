cbuffer Reflectivity
{
    float reflectivity;
};

TextureCube<float4> cubeTexture;
SamplerState cubeSampler;

struct PS_INPUT
{
    float4 vertexColor : COLOR;
    float3 cubeTextureCoordinate : TEXCOORD0;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET;
};

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;
    float4 reflectedColor = cubeTexture.Sample(cubeSampler, input.cubeTextureCoordinate);
    output.pixelColor = lerp(input.vertexColor, reflectedColor, reflectivity);
    return output;
}