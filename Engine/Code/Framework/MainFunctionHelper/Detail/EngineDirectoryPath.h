// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:25)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_PATH_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_PATH_H

#include "Framework/FrameworkDll.h" 

#include "EngineDirectoryResult.h"

#include <map>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EngineDirectoryPath
	{
	public:
		using ClassType = EngineDirectoryPath;
		using String = System::String;

	public:
		explicit EngineDirectoryPath(const EngineDirectoryResult& result);

		CLASS_INVARIANT_DECLARE;

		const String GetDirectory(AnalysisDirectory analysisDirectory) const;
		const String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const;

	private:
		using IndexType = std::tuple<EndianDirectory, RenderingDirectory, AnalysisDirectory>;
		using PathType = std::map<IndexType, String>;

	private:
		void Analysis();
		void Analysis(RenderingDirectory renderingDirectory);
		void Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory);
		void Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory);

		const String GetDirectoryResult(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory);

	private:
		EngineDirectoryResult m_Result;
		PathType m_PathType;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_PATH_H