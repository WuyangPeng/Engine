uniform Translate
{
    vec3 translate;
};

layout(location = 0) in vec2 modelPosition;
layout(location = 1) in vec2 modelTCoord;
layout(location = 0) out vec2 vertexTCoord;

void main()
{
    vertexTCoord = modelTCoord;
    gl_Position.x = 2.0f * modelPosition.x - 1.0f + 2.0f * translate.x;
    gl_Position.y = 2.0f * modelPosition.y - 1.0f + 2.0f * translate.y;
    gl_Position.z = translate.z;
    gl_Position.w = 1.0f;
}