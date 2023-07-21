uniform ZNDC
{
    float zNDC;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec2 modelTCoord;
layout(location = 0) out vec2 vertexTCoord;

void main()
{
    vertexTCoord = modelTCoord;
    gl_Position.x = 2.0f*modelPosition.x - 1.0f;
    gl_Position.y = -2.0f*modelPosition.y + 1.0f;
    gl_Position.z = zNDC;
    gl_Position.w = 1.0f;
}