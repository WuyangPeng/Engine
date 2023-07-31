uniform Reflectivity
{
	float reflectivity;
};

uniform samplerCube cubeSampler;

layout(location = 0) in vec4 vertexColor;
layout(location = 1) in vec3 cubeTextureCoordinate;

layout(location = 0) out vec4 pixelColor;

void main()
{
	vec4 reflectedColor = texture(cubeSampler, cubeTextureCoordinate);
 
	float s = clamp(reflectivity, 0.0f, 1.0f);
	pixelColor = vertexColor + s * (reflectedColor - vertexColor);
}