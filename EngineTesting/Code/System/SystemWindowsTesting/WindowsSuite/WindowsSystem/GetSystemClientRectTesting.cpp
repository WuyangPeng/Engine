/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:18)

#include "GetSystemClientRectTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSystemClientRectTesting::GetSystemClientRectTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSystemClientRectTesting)

void System::GetSystemClientRectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetSystemClientRectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemClientRectTest);
}

void System::GetSystemClientRectTesting::GetSystemClientRectTest()
{
    WindowsRect windowsRect{};
    ASSERT_TRUE(GetSystemClientRect(hWnd, windowsRect));

    ASSERT_LESS(0, windowsRect.right);
    ASSERT_LESS(0, windowsRect.bottom);
}
