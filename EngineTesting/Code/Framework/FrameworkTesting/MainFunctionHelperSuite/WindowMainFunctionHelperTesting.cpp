///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:16)

#include "WindowMainFunctionHelperTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Framework::WindowMainFunctionHelperTesting::WindowMainFunctionHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMainFunctionHelperTesting)

void Framework::WindowMainFunctionHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMainFunctionHelperTesting::MainTest()
{
    // �����WindowMainFunctionHelperʹ�ù�������ã��޷��������е�Ԫ���ԡ�

    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    ASSERT_NOT_THROW_EXCEPTION_0(WindowMainFunctionHelper1Test);
}

void Framework::WindowMainFunctionHelperTesting::WindowMainFunctionHelper1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WindowMainFunctionHelper1")));
}
