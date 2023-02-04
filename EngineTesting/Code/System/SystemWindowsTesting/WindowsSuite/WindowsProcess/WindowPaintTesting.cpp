///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:11)

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
    ASSERT_NOT_THROW_EXCEPTION_0(SystemPaintTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CursorPosTest);
}

void System::WindowPaintTesting::SystemPaintTest()
{
    WindowsPaintStruct ps{};
    ASSERT_TRUE(SystemBeginPaint(hwnd, &ps));
    ASSERT_TRUE(SystemEndPaint(hwnd, &ps));
}

void System::WindowPaintTesting::CursorPosTest()
{
    WindowsPoint point0{};

    ASSERT_NOT_THROW_EXCEPTION_1(SetCursorClientPosTest, point0);

    WindowsPoint point1{};

    ASSERT_NOT_THROW_EXCEPTION_2(GetCursorClientPosTest, point0, point1);
    ASSERT_NOT_THROW_EXCEPTION_2(ScreenTest, point0, point1);
}

void System::WindowPaintTesting::SetCursorClientPosTest(WindowsPoint& point)
{
    ASSERT_TRUE(GetCursorClientPos(hwnd, point));
    ASSERT_TRUE(SetCursorClientPos(hwnd, point));
}

void System::WindowPaintTesting::GetCursorClientPosTest(WindowsPoint& lhsPoint, WindowsPoint& rhsPoint)
{
    ASSERT_TRUE(GetCursorClientPos(hwnd, rhsPoint));
    ASSERT_EQUAL(lhsPoint.x, rhsPoint.x);
    ASSERT_EQUAL(lhsPoint.y, rhsPoint.y);

    ASSERT_TRUE(GetSystemCursorPos(lhsPoint));
    ASSERT_TRUE(SystemScreenToClient(hwnd, lhsPoint));
}

void System::WindowPaintTesting::ScreenTest(const WindowsPoint& lhsPoint, WindowsPoint& rhsPoint)
{
    WindowsPoint point{ lhsPoint };
    ASSERT_TRUE(SystemClientToScreen(hwnd, point));
    ASSERT_TRUE(SetSystemCursorPos(point));

    ASSERT_TRUE(GetSystemCursorPos(rhsPoint));
    ASSERT_TRUE(SystemScreenToClient(hwnd, rhsPoint));

    ASSERT_EQUAL(lhsPoint.x, rhsPoint.x);
    ASSERT_EQUAL(lhsPoint.y, rhsPoint.y);
}
