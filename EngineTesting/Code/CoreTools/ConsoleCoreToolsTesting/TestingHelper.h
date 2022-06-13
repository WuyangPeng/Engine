///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 16:40)

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