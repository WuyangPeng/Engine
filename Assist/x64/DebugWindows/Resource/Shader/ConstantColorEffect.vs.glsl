uniform ProjectionViewWorldMatrix
{
    mat4 projectionViewWorldMatrix;
};

uniform ConstantColor
{
    vec4 constantColor;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 0) out vec4 vertexColor;

void main()
{
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);

    vertexColor = constantColor;
}