@echo on
 
set ProjectDir=%1
set ShaderDir=%2

xcopy "%EngineInclude%/Rendering/LocalEffects/Shader/*.*" "%ProjectDir%/Resource/Shader/" /F /Y
xcopy "%EngineInclude%/Rendering/LocalEffects/Shader/*.*" "%ShaderDir%" /F /Y