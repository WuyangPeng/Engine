/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:17)

#include "WindowPaintTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowPaintTesting::WindowPaintTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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
    ASSERT_TRUE(SystemBeginPaint(hWnd, &ps));
    ASSERT_TRUE(SystemEndPaint(hWnd, &ps));
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
    ASSERT_TRUE(GetCursorClientPos(hWnd, point));
    ASSERT_TRUE(SetCursorClientPos(hWnd, point));
}

void System::WindowPaintTesting::GetCursorClientPosTest(WindowsPoint& lhsPoint, WindowsPoint& rhsPoint)
{
    ASSERT_TRUE(GetCursorClientPos(hWnd, rhsPoint));
    ASSERT_EQUAL(lhsPoint.x, rhsPoint.x);
    ASSERT_EQUAL(lhsPoint.y, rhsPoint.y);

    ASSERT_TRUE(GetSystemCursorPos(lhsPoint));
    ASSERT_TRUE(SystemScreenToClient(hWnd, lhsPoint));
}

void System::WindowPaintTesting::ScreenTest(const WindowsPoint& lhsPoint, WindowsPoint& rhsPoint)
{
    WindowsPoint point{ lhsPoint };
    ASSERT_TRUE(SystemClientToScreen(hWnd, point));
    ASSERT_TRUE(SetSystemCursorPos(point));

    ASSERT_TRUE(GetSystemCursorPos(rhsPoint));
    ASSERT_TRUE(SystemScreenToClient(hWnd, rhsPoint));

    ASSERT_EQUAL(lhsPoint.x, rhsPoint.x);
    ASSERT_EQUAL(lhsPoint.y, rhsPoint.y);
}
