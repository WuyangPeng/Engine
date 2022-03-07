///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/30 19:17)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

ConsoleCoreToolsTesting::TestingHelper::TestingHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }, consoleAlloc{ ConsoleAlloc::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ConsoleCoreToolsTesting, TestingHelper)

int ConsoleCoreToolsTesting::TestingHelper ::EnterMessageLoop()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cout << "一共有两行消息显示在控制台。" << endl;
    cerr << "控制台没有关闭按钮。" << endl;

    return ParentType::EnterMessageLoop();
}
