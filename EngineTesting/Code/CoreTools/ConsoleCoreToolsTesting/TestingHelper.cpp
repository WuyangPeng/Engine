///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 16:40)

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

ConsoleCoreToolsTesting::TestingHelper::TestingHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }, consoleAlloc{ ConsoleAlloc::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ConsoleCoreToolsTesting, TestingHelper)

int ConsoleCoreToolsTesting::TestingHelper::EnterMessageLoop()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cout << "һ����������Ϣ��ʾ�ڿ���̨��" << endl;
    cerr << "����̨û�йرհ�ť��" << endl;

    return ParentType::EnterMessageLoop();
}
