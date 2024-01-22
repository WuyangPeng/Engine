uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
};

uniform WorldMatrix
{
	mat4 worldMatrix;
};

uniform CameraWorldPosition
{
	vec4 cameraWorldPosition;
};

layout(location = 0) in vec3 modelPosition;
layout(location = 1) in vec3 modelNormal;
layout(location = 2) in vec4 modelColor;

layout(location = 0) out vec4 vertexColor;
layout(location = 1) out vec3 cubeTextureCoordinate;

void main()
{
	vec4 hModelPosition = vec4(modelPosition, 1.0f);
	vec3 worldPosition;
	vec3 worldNormal;
 
	gl_Position = projectionViewWorldMatrix * hModelPosition;
	worldPosition = (worldMatrix * hModelPosition).xyz;
	worldNormal = normalize(worldMatrix * vec4(modelNormal, 0.0f)).xyz; 
 
	vec3 eyeDirection = worldPosition - cameraWorldPosition.xyz;
 
	cubeTextureCoordinate = reflect(eyeDirection, worldNormal);
 
	vertexColor = modelColor;
}