///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/17 22:57)

#include "ConsoleCreateTesting.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Console/ConsoleHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCreateTesting::ConsoleCreateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleCreateTesting)

void System::ConsoleCreateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleCreateTesting::MainTest() 
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemConsoleWindowTest);

    // ConsoleCreate�ĵ�Ԫ����ʹ��ConsoleSystemTesting���С�
}

void System::ConsoleCreateTesting::GetSystemConsoleWindowTest()
{
    auto windowHWnd = GetSystemConsoleWindow();

    ASSERT_TRUE(IsHandleValid(windowHWnd));
}