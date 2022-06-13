///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/16 16:40)

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
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using ConsoleAlloc = CoreTools::ConsoleAlloc;

    public:
        TestingHelper(WindowsHInstance instance,
                      const char* commandLine,
                      const WindowApplicationInformation& information,
                      const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD int EnterMessageLoop() final;

    private:
        ConsoleAlloc consoleAlloc;
    };
}

#endif  // CONSOLE_CORE_TOOLS_TESTING_TESTING_HELPER_H