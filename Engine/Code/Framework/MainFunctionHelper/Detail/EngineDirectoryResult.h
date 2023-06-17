///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:38)

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

        NODISCARD String GetDirectory(RenderingDirectory renderingDirectory, AnalysisDirectory analysisDirectory) const;
        NODISCARD String GetDirectory(AnalysisDirectory analysisDirectory) const;

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
        ResultType result;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ENGINE_DIRECTORY_RESULT_H