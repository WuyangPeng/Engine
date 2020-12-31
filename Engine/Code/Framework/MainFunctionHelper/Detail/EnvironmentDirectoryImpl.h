// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:29)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "EngineDirectoryPath.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <map>
#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EnvironmentDirectoryImpl
	{
	public:
		using ClassType = EnvironmentDirectoryImpl;
		using String = System::String;

	public:
		EnvironmentDirectoryImpl(const String& engineEnvironment, const String& engineDirectory);

		CLASS_INVARIANT_DECLARE;

		const String GetEngineEnvironment() const;
		const String GetEngineDirectory() const;

		const String GetDirectory(UpperDirectory analysisDirectory) const;

		const String GetPath(RenderingAnalysisDirectory analysisDirectory) const;
		const String GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;
		const String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;

	private:
		static const String GenerateEngineDirectory(const String& engineEnvironment);
		static const EngineDirectoryPath GetEngineDirectoryPath(const String& engineDirectory);
		static const std::string GetJsonName(const String& variableName);

	private:
		String m_EngineEnvironment;
		String m_EngineDirectory;
		EngineDirectoryPath m_EngineDirectoryPath;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H