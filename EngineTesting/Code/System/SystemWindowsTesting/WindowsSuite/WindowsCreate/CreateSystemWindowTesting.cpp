/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:16)

#include "CreateSystemWindowTesting.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSystemWindowTesting::CreateSystemWindowTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd)
    : ParentType{ stream, instance, hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSystemWindowTesting)

void System::CreateSystemWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSystemWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSystemWindowTest);
}

void System::CreateSystemWindowTesting::CreateSystemWindowTest()
{
    const auto className = GetWindowsClassName();

    const auto systemWindow = CreateWindowTest(className);
    ASSERT_UNEQUAL_NULL_PTR(systemWindow);

    ASSERT_NOT_THROW_EXCEPTION_2(ResultTest, systemWindow, className);
}

void System::CreateSystemWindowTesting::ResultTest(WindowsHWnd systemWindow, const String& className)
{
    String resultClassName{};
    String resultWindowsName{};

    ASSERT_TRUE(GetSystemClassName(systemWindow, resultClassName));
    ASSERT_EQUAL(resultClassName, className);

    ASSERT_TRUE(GetWindowTextString(systemWindow, resultWindowsName));
    ASSERT_EQUAL(resultWindowsName, GetWindowsName());
}
