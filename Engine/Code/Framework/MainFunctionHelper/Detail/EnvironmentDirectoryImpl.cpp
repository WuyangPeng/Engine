// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:54)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectoryImpl.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ExceptionMacro.h"

const System::String Framework::EnvironmentDirectoryImpl
	::sm_Suffix(SYSTEM_TEXT("/"));

Framework::EnvironmentDirectoryImpl
	::EnvironmentDirectoryImpl(const System::String& engineEnvironment)
	:m_EngineEnvironment(engineEnvironment),
	 m_EngineDirectory(GenerateEngineDirectory(engineEnvironment)),
	 m_ResourcePath(SYSTEM_TEXT("Resource")),	
	 m_ConfigurationPath(SYSTEM_TEXT("Configuration")),			
	 m_ShaderPath(SYSTEM_TEXT("Shader")),		
	 m_ScenePath(SYSTEM_TEXT("Scene")),	
	 m_TexturePath(SYSTEM_TEXT("Texture")),			
	 m_VertexPath(SYSTEM_TEXT("Vertex")),			
	 m_ImagePath(SYSTEM_TEXT("Image"))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::EnvironmentDirectoryImpl
	::IsValid() const noexcept
{
	if(!m_EngineEnvironment.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

const System::String Framework::EnvironmentDirectoryImpl
	::GetEngineEnvironment() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_EngineEnvironment;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetEngineDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if(!m_EngineDirectory.empty())
		return m_EngineDirectory + sm_Suffix;
	else
		return SYSTEM_TEXT("");
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetResourcePath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetEngineDirectory() + m_ResourcePath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetConfigurationPath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetEngineDirectory() + m_ConfigurationPath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetShaderPath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetResourcePath() + m_ShaderPath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetScenePath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetResourcePath() + m_ScenePath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetTexturePath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetResourcePath() + m_TexturePath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetVertexPath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetResourcePath() + m_VertexPath + sm_Suffix;
}

const System::String Framework::EnvironmentDirectoryImpl
	::GetImagePath() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetResourcePath() + m_ImagePath + sm_Suffix;
}

void Framework::EnvironmentDirectoryImpl
	::SetResourcePath(const System::String& resourcePath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ResourcePath = resourcePath;
}

void Framework::EnvironmentDirectoryImpl
	::SetConfigurationPath(const System::String& configurationPath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ConfigurationPath = configurationPath;
}

void Framework::EnvironmentDirectoryImpl
	::SetShaderPath(const System::String& shaderPath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ShaderPath = shaderPath;
}

void Framework::EnvironmentDirectoryImpl
	::SetScenePath(const System::String& scenePath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ScenePath = scenePath;
}

void Framework::EnvironmentDirectoryImpl
	::SetTexturePath(const System::String& texturePath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TexturePath = texturePath;
}

void Framework::EnvironmentDirectoryImpl
	::SetVertexPath(const System::String& vertexPath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_VertexPath = vertexPath;
}

void Framework::EnvironmentDirectoryImpl
	::SetImagePath(const System::String& imagePath)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ImagePath = imagePath;
}

// static
// private
const System::String Framework::EnvironmentDirectoryImpl
	::GenerateEngineDirectory(const System::String& engineEnvironment)
{
	CoreTools::EnvironmentVariable variable(engineEnvironment);
	System::String engineInstallationDirectory = variable.GetVariable(); 
	 
	return engineInstallationDirectory;
}


