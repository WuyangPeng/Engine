///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:45)

#include "ConsoleMainFunctionHelperBaseTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ConsoleMainFunctionHelperBaseTesting::ConsoleMainFunctionHelperBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ConsoleMainFunctionHelperBaseTesting)

void Framework::ConsoleMainFunctionHelperBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ConsoleMainFunctionHelperBaseTesting::MainTest()
{
    // �����ConsoleMainFunctionHelperBaseʹ�ù�������ã��޷��������е�Ԫ���ԡ�

    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleMainFunctionHelperBase1Test);
}

void Framework::ConsoleMainFunctionHelperBaseTesting::ConsoleMainFunctionHelperBase1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("ConsoleMainFunctionHelperBase1")));
}
