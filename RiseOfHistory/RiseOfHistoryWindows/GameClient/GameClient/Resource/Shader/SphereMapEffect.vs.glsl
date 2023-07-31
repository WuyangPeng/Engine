uniform ProjectionViewWorldMatrix
{
	mat4 projectionViewWorldMatrix;
};

uniform VWMatrix
{
    mat4 vwMatrix;
};

layout(location = 0) in vec3 inModelPosition;
layout(location = 1) in vec3 inModelNormal;

layout(location = 0) out vec2 vertexTCoord;

void main()
{
    vec4 modelPosition = vec4(inModelPosition, 1.0f);
    vec4 modelNormal = vec4(inModelNormal, 0.0f);

    vec4 cameraSpacePosition = vwMatrix * modelPosition;
    vec3 cameraSpaceNormal = normalize((vwMatrix * modelNormal).xyz);
    gl_Position = projectionViewWorldMatrix * modelPosition;
  
    vec3 eyeDirection = normalize(cameraSpacePosition.xyz);
    vec3 r = reflect(eyeDirection, cameraSpaceNormal);
    
    float oneMRZ = 1.0f - r.z;
    float invLength = 1.0f / sqrt(r.x * r.x + r.y * r.y + oneMRZ * oneMRZ);
    vertexTCoord = 0.5f * (r.xy * invLength + 1.0f);
}