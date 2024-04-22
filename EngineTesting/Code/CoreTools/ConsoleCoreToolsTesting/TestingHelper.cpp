/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 18:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

#include <iostream>

ConsoleCoreToolsTesting::TestingHelper::TestingHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }, consoleAlloc{ ConsoleAlloc::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ConsoleCoreToolsTesting, TestingHelper)

int ConsoleCoreToolsTesting::TestingHelper::EnterMessageLoop()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    std::cout << "一共有两行消息显示在控制台。" << std::endl;
    std::cerr << "控制台没有关闭按钮。" << std::endl;

    return ParentType::EnterMessageLoop();
}
