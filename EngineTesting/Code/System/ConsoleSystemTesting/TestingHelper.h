///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/20 11:58)

#ifndef CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H
#define CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H

#include "Console/ConsoleHelper.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace ConsoleSystemTesting
{
    using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;

    class TestingHelper final : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;

        using WindowsHInstance = System::WindowsHInstance;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        TestingHelper(WindowsHInstance instance,
                      const char* commandLine,
                      const WindowApplicationInformation& information,
                      const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD int EnterMessageLoop() final;

    private:
        ConsoleHelper consoleHelper;
    };
}

#endif  // CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H