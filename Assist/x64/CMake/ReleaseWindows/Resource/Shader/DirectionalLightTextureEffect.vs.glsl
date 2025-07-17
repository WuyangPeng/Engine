uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;
layout(location = 2) in vec2 modelTCoord;
layout(location = 0) out vec3 vertexPosition;
layout(location = 1) out vec3 vertexNormal;
layout(location = 2) out vec2 vertexTCoord;

void main()
{
    vertexPosition = modelPosition;
    vertexNormal = modelNormal;
    vertexTCoord = modelTCoord;
    
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);

}