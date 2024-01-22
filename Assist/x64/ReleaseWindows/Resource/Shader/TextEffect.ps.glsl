uniform TextColor
{
    vec4 textColor;
};

layout(location = 0) in vec2 vertexTCoord;
layout(location = 0) out vec4 pixelColor;

uniform sampler2D baseSampler;

void main()
{
    float bitmapAlpha = texture(baseSampler, vertexTCoord).r;
    if (bitmapAlpha > 0.5f)
    {
        discard;
    }
    pixelColor = textColor;
}