cbuffer Material
{
    float4 materialEmissive;
    float4 materialAmbient;
    float4 materialDiffuse;
    float4 materialSpecular;
};

cbuffer Camera
{
    float4 cameraModelPosition;
};

cbuffer AreaLight
{
    float4 lightingAmbient;
    float4 lightingDiffuse;
    float4 lightingSpecular;
    float4 lightingAttenuation;

    float4 rectPosition;
    float4 rectNormal;
    float4 rectAxis0;
    float4 rectAxis1;
    float4 rectExtent;
};

Texture2D<float4> baseTexture;
SamplerState baseSampler;

Texture2D<float4> normalTexture;
SamplerState normalSampler;

struct PS_INPUT
{
    float4 vertexPosition : TEXCOORD0;
    float2 vertexTextureCoordinate : TEXCOORD1;
};

struct PS_OUTPUT
{
    float4 pixelColor : SV_TARGET0;
};

float4 ComputeLightModelPosition(in float4 vertexPosition)
{
    float4 diff = vertexPosition - rectPosition;
    float2 crd = float2(dot(rectAxis0, diff), dot(rectAxis1, diff));
    crd = clamp(crd, -rectExtent.xy, rectExtent.xy);
    float4 closest = rectPosition + crd.x * rectAxis0 + crd.y * rectAxis1;
    return closest;
}

PS_OUTPUT PSMain(PS_INPUT input)
{
    PS_OUTPUT output;

    float4 lightModelPosition = ComputeLightModelPosition(input.vertexPosition);
    float3 modelLightDiff = input.vertexPosition.xyz - lightModelPosition.xyz;
    float distance = length(modelLightDiff);
    float attenuation = lightingAttenuation.w / (lightingAttenuation.x + distance * (lightingAttenuation.y + distance * lightingAttenuation.z));

    float3 vertexNormal = normalTexture.Sample(normalSampler, input.vertexTextureCoordinate).rgb;
    vertexNormal = normalize(2.0f * vertexNormal - 1.0f);

    float3 vertexDirection = normalize(modelLightDiff);
    float nDotL = -dot(vertexNormal, vertexDirection);
    float3 viewVector = normalize(cameraModelPosition.xyz - input.vertexPosition.xyz);
    float3 halfVector = normalize(viewVector - vertexDirection);
    float nDotH = dot(vertexNormal, halfVector);
    float4 lighting = lit(nDotL, nDotH, materialSpecular.a);

    float3 emissive = materialEmissive.rgb;
    float3 ambient = materialAmbient.rgb * lightingAmbient.rgb;
    float4 textureDiffuse = baseTexture.Sample(baseSampler, input.vertexTextureCoordinate);
    float3 diffuse = materialDiffuse.rgb * textureDiffuse.rgb * lightingDiffuse.rgb;
    float3 specular = materialSpecular.rgb * lightingSpecular.rgb;

    float3 colorRGB = emissive + attenuation * (ambient + lighting.y * diffuse + lighting.z * specular);
    float colorA = materialDiffuse.a * textureDiffuse.a;
    output.pixelColor = float4(colorRGB, colorA);

    return output;
}