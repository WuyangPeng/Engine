// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:29)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_RESULT_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_RESULT_H

#include "Framework/FrameworkDll.h" 

#include "System/Helper/UnicodeUsing.h"  
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <map>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EngineDirectoryResult
	{
	public:
		using ClassType = EngineDirectoryResult;
		using String = System::String;

	public:
		CLASS_INVARIANT_DECLARE;

		const String GetDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const;
		const String GetDirectory(AnalysisDirectory analysisDirectory) const;

		void InsertDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const String& directory);

		void SetDefaultDirectory();

	private:
		using ResultIndex = std::pair<RenderingDirectory, AnalysisDirectory>;
		using ResultType = std::map<ResultIndex, String>;

	private:
		void SetDefaultBaseDirectory();
		void SetDefaultBaseDirectory(AnalysisDirectory analysisDirectory);
		void SetDefaultRenderingDirectory();
		void SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory);
		void SetDefaultRenderingDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory);

	private:
		ResultType m_Result;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_RESULT_H