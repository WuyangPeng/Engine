uniform ProjectionViewWorldMatrix
{
    mat4 projectionViewWorldMatrix;
};

uniform Material
{
    vec4 materialEmissive;
    vec4 materialAmbient;
};

uniform Light
{
    vec4 lightingAmbient;
    vec4 lightingAttenuation;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 0) out vec4 vertexColor;

void main()
{
    vec3 ambient = lightingAttenuation.w * lightingAmbient.rgb;
    vertexColor.rgb = materialEmissive.rgb + materialAmbient.rgb * ambient;
    vertexColor.a = 1.0f;
   
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);   
};
 