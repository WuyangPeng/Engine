/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:51)

#ifndef CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H
#define CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H

#include "Testing.h"
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
        NODISCARD int EnterMessageLoop() override;

    private:
        ConsoleHelper consoleHelper;
    };
}

#endif  // CONSOLE_SYSTEM_TESTING_TESTING_HELPER_H