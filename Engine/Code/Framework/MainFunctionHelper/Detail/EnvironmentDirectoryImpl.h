// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:50)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EnvironmentDirectoryImpl
	{
	public:
		using ClassType = EnvironmentDirectoryImpl;

	public:
		explicit EnvironmentDirectoryImpl(const System::String& engineEnvironment);

		CLASS_INVARIANT_DECLARE;

		const System::String GetEngineEnvironment() const;
		const System::String GetEngineDirectory() const;
		const System::String GetResourcePath() const;		
		const System::String GetConfigurationPath() const;		
		const System::String GetShaderPath() const;	
		const System::String GetScenePath() const;		
		const System::String GetTexturePath() const;		
		const System::String GetVertexPath() const;		
		const System::String GetImagePath() const;		

		void SetResourcePath(const System::String& resourcePath);
		void SetConfigurationPath(const System::String& configurationPath);
		void SetShaderPath(const System::String& shaderPath);
		void SetScenePath(const System::String& scenePath);
		void SetTexturePath(const System::String& texturePath);
		void SetVertexPath(const System::String& vertexPath);
		void SetImagePath(const System::String& imagePath);

	private:
		static const System::String GenerateEngineDirectory(const System::String& engineEnvironment);

	private:
		System::String m_EngineEnvironment;
		System::String m_EngineDirectory;		 
		System::String m_ResourcePath;		
		System::String m_ConfigurationPath;		
		System::String m_ShaderPath;		
		System::String m_ScenePath;	
		System::String m_TexturePath;		
		System::String m_VertexPath;		
		System::String m_ImagePath;	

		static const System::String sm_Suffix;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H