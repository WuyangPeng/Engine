///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:55)

#include "MousePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/MousePosition.h"
#include "Framework/WindowCreate/WindowPoint.h"

Framework::MousePositionTesting::MousePositionTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MousePositionTesting)

void Framework::MousePositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MousePositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowMousePositionTest);
}

void Framework::MousePositionTesting::WindowMousePositionTest()
{
    MousePosition windowMousePosition{ hWnd };

    const auto point0 = windowMousePosition.GetMousePosition();
    windowMousePosition.SetMousePosition(point0);

    const auto point1 = windowMousePosition.GetMousePosition();

    ASSERT_EQUAL(point0, point1);
}
