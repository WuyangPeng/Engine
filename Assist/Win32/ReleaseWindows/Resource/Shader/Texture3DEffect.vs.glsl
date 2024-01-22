uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
}; 
    
layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelTCoord;
layout(location = 0) out vec3 vertexTCoord;

void main()
{
    vertexTCoord = modelTCoord;
 
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);
}