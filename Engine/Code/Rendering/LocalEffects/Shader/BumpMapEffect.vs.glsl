uniform ProjectionViewWorldMatrix
{
    mat4 projectionViewWorldMatrix;
};
 
layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;  
layout(location = 2) in vec3 modelLightDirection;
layout(location = 3) in vec2 modelBaseTextureCoordinate;
layout(location = 4) in vec2 modelNormalTextureCoordinate;
layout(location = 0) out vec3 vertexLightDirection;
layout(location = 1) out vec2 vertexBaseTextureCoordinate;
layout(location = 2) out vec2 vertexNormalTextureCoordinate;

void main()
{
    vertexLightDirection = modelLightDirection;
    vertexBaseTextureCoordinate = modelBaseTextureCoordinate;
    vertexNormalTextureCoordinate = modelNormalTextureCoordinate;
    
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);
}