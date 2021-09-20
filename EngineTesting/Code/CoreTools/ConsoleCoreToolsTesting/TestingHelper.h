///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/30 19:16)

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
        TestingHelper(HInstance instance,
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