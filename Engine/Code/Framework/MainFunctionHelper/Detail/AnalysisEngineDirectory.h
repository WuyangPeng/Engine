/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/06 18:10)

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

        NODISCARD EngineDirectoryResult GetEngineDirectoryResult() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Init(const std::string& jsonName);
        void Analysis(const std::string& jsonName);
        void DoAnalysis(const std::string& jsonName);
        void AnalysisBase();
        void AnalysisRendering();
        void AnalysisRendering(RenderingDirectory renderingDirectory);
        void DoAnalysisRendering(RenderingDirectory renderingDirectory);
        void AnalysisRendering(RenderingDirectory renderingDirectory, const BasicTree& renderingTree);
        void InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory);
        void InsertResult(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory, const BasicTree& renderingTree);

    private:
        BasicTree basicTree;
        BasicTree resourceTree;
        BasicTree configurationTree;
        EngineDirectoryResult result;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ANALYSIS_ENGINE_DIRECTORY_H