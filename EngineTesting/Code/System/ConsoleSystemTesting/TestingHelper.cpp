/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:51)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

ConsoleSystemTesting::TestingHelper::TestingHelper(WindowsHInstance instance,
                                                   const char* commandLine,
                                                   const WindowApplicationInformation& information,
                                                   const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory },
      consoleHelper{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ConsoleSystemTesting, TestingHelper)

int ConsoleSystemTesting::TestingHelper::EnterMessageLoop()
{
    SYSTEM_CLASS_IS_VALID_1;

    if (consoleHelper.IsSuccess())
    {
        ConsoleHelper::PrintConsoleInfo();

        return ParentType::EnterMessageLoop();
    }
    else
    {
        return -1;
    }
}
