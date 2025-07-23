uniform ProjectionViewWorldMatrix
{
    mat4 projectionViewWorldMatrix;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec2 modelTextureCoordinate;
layout(location = 0) out vec4 vertexPosition;
layout(location = 1) out vec2 vertexTextureCoordinate;

void main()
{
    vertexPosition = vec4(modelPosition, 1.0f);
    vertexTextureCoordinate = modelTextureCoordinate;
 
    gl_Position = projectionViewWorldMatrix * vertexPosition;
}