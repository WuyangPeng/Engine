///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:31)

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

        NODISCARD String GetDirectory(AnalysisDirectory analysisDirectory) const;
        NODISCARD String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const;

    private:
        using IndexType = std::tuple<EndianDirectory, RenderingDirectory, AnalysisDirectory>;
        using PathType = std::map<IndexType, String>;

    private:
        void Analysis();
        void Analysis(RenderingDirectory renderingDirectory);
        void Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory);
        void Analysis(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory);

        NODISCARD String GetDirectoryResult(RenderingDirectory renderingDirectory, EndianDirectory endianDirectory, AnalysisDirectory analysisDirectory);

    private:
        EngineDirectoryResult result;
        PathType pathType;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_PATH_H