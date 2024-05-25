/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 18:10)

#ifndef CONSOLE_CORE_TOOLS_TESTING_TESTING_HELPER_H
#define CONSOLE_CORE_TOOLS_TESTING_TESTING_HELPER_H

#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace ConsoleCoreToolsTesting
{
    using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
    class TestingHelper final : public WindowMainFunctionHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = WindowMainFunctionHelper;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        TestingHelper(WindowsHInstance instance,
                      const char* commandLine,
                      const WindowApplicationInformation& information,
                      const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD int EnterMessageLoop() override;

    private:
        ConsoleAlloc consoleAlloc;
    };
}

#endif  // CONSOLE_CORE_TOOLS_TESTING_TESTING_HELPER_H