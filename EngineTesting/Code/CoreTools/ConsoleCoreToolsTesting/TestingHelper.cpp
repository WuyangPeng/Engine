///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/14 15:55)

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

    std::cout << "һ����������Ϣ��ʾ�ڿ���̨��" << std::endl;
    std::cerr << "����̨û�йرհ�ť��" << std::endl;

    return ParentType::EnterMessageLoop();
}
