/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:15)

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

        NODISCARD String GetEngineEnvironment() const;
        NODISCARD String GetEngineDirectory() const;

        NODISCARD String GetDirectory(UpperDirectory analysisDirectory) const;

        NODISCARD String GetPath(RenderingAnalysisDirectory analysisDirectory) const;
        NODISCARD String GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;
        NODISCARD String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;

    private:
        NODISCARD static String GenerateEngineDirectory(const String& engineEnvironment);
        NODISCARD static EngineDirectoryPath GetEngineDirectoryPath(const String& engineDirectory);
        NODISCARD static std::string GetJsonName(const String& variableName);

    private:
        String engineEnvironment;
        String engineDirectory;
        EngineDirectoryPath engineDirectoryPath;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_IMPL_H