uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
}; 
    
layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec2 modelTCoord;
layout(location = 0) out vec2 vertexTCoord;

void main()
{
    vertexTCoord = modelTCoord;
  
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);
}