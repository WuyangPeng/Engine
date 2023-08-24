///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 19:28)

#include "MainFunctionHelperBaseTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Framework::MainFunctionHelperBaseTesting::MainFunctionHelperBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionHelperBaseTesting)

void Framework::MainFunctionHelperBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MainFunctionHelperBaseTesting::MainTest()
{
    // �����MainFunctionHelperBaseʹ�ù�������ã��޷��������е�Ԫ���ԡ�

    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    ASSERT_NOT_THROW_EXCEPTION_0(MainFunctionHelperBase1Test);
}

void Framework::MainFunctionHelperBaseTesting::MainFunctionHelperBase1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MainFunctionHelperBase1")));
}
