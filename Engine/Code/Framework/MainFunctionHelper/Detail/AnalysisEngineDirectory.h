// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:23)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANALYSIS_ENGINE_DIRECTORY_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANALYSIS_ENGINE_DIRECTORY_H

#include "Framework/FrameworkDll.h" 

#include "EngineDirectoryResult.h"
#include "System/Helper/PragmaWarning/PropertyTree.h" 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE AnalysisEngineDirectory
	{
	public:
		using ClassType = AnalysisEngineDirectory;
		using String = System::String;

	public:
		explicit AnalysisEngineDirectory(const std::string& jsonName);

		CLASS_INVARIANT_DECLARE;

		const EngineDirectoryResult GetEngineDirectoryResult() const;

	private:
		using BasicTree = boost::property_tree::basic_ptree<String, String>;

	private:
		void Analysis(const std::string& jsonName);
		void AnalysisBase();
		void AnalysisRendering();
		void AnalysisRendering(RenderingDirectory renderingDirectory);
		void AnalysisRendering(RenderingDirectory renderingDirectory, const BasicTree& renderingTree);
		void InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory);
		void InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const BasicTree& renderingTree);

	private:
		BasicTree m_BasicTree;
		BasicTree m_ResourceTree;
		BasicTree m_ConfigurationTree;
		EngineDirectoryResult m_Result;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ANALYSIS_ENGINE_DIRECTORY_H