///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:46)

#include "GetSystemClientRectTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSystemClientRectTesting::GetSystemClientRectTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    ASSERT_TRUE(GetSystemClientRect(hwnd, windowsRect));

    ASSERT_LESS(0, windowsRect.right);
    ASSERT_LESS(0, windowsRect.bottom);
}
