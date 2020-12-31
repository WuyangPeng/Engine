// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:22)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H

#include "Framework/FrameworkDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(EnvironmentDirectoryImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE EnvironmentDirectory
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(EnvironmentDirectory);
		using String = System::String;

	public:
		explicit EnvironmentDirectory(const String& engineEnvironment, const String& engineDirectory);

		CLASS_INVARIANT_DECLARE;

		const String GetEngineEnvironment() const;
		const String GetEngineDirectory() const;

		const String GetDirectory(UpperDirectory analysisDirectory) const;

		const String GetPath(RenderingAnalysisDirectory analysisDirectory) const;
		const String GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;
		const String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;

	private:
		IMPL_TYPE_DECLARE(EnvironmentDirectory);
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H