///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:45)

#include "WindowPaintTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowPaintTesting::WindowPaintTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowPaintTesting)

void System::WindowPaintTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowPaintTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PeekMessageTest);
}

void System::WindowPaintTesting::PeekMessageTest()
{
    WindowsPoint point0{};

    ASSERT_TRUE(GetCursorClientPos(hwnd, point0));

    WindowsPaintStruct ps{};
    ASSERT_TRUE(SystemBeginPaint(hwnd, &ps));
    ASSERT_TRUE(SystemEndPaint(hwnd, &ps));

    ASSERT_TRUE(SetCursorClientPos(hwnd, point0));

    WindowsPoint point1{};

    ASSERT_TRUE(GetCursorClientPos(hwnd, point1));

    ASSERT_EQUAL(point0.x, point1.x);
    ASSERT_EQUAL(point0.y, point1.y);

    ASSERT_TRUE(GetSystemCursorPos(point0));
    ASSERT_TRUE(SystemScreenToClient(hwnd, point0));

    WindowsPoint point2{ point0 };
    ASSERT_TRUE(SystemClientToScreen(hwnd, point2));
    ASSERT_TRUE(SetSystemCursorPos(point2));

    ASSERT_TRUE(GetSystemCursorPos(point1));
    ASSERT_TRUE(SystemScreenToClient(hwnd, point1));

    ASSERT_EQUAL(point0.x, point1.x);
    ASSERT_EQUAL(point0.y, point1.y);
}
