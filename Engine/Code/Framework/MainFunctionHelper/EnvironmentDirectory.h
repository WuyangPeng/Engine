/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(EnvironmentDirectoryImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE EnvironmentDirectory
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(EnvironmentDirectory);

        using String = System::String;

    public:
        explicit EnvironmentDirectory(const String& engineEnvironment, const String& engineDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetEngineEnvironment() const;
        NODISCARD String GetEngineDirectory() const;

        NODISCARD String GetDirectory(UpperDirectory analysisDirectory) const;
        NODISCARD String GetServerConfigurationDirectory() const;

        NODISCARD String GetPath(RenderingAnalysisDirectory analysisDirectory) const;
        NODISCARD String GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;
        NODISCARD String GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ENVIRONMENT_DIRECTORY_H