// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H

#include "Framework/FrameworkDll.h" 

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(EnvironmentDirectoryImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE EnvironmentDirectory
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(EnvironmentDirectory);

	public:
		explicit EnvironmentDirectory(const System::String& engineEnvironment);

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
		IMPL_TYPE_DECLARE(EnvironmentDirectory);
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H