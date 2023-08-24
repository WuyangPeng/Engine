uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
}; 
    
layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec4 modelColor;
layout(location = 0) out vec4 vertexColor;

void main()
{
    vertexColor = modelColor;
 
    gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f);
    
}