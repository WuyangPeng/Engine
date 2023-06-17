///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:10)
 
#include "MousePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/MousePosition.h"
#include "Framework/WindowCreate/WindowPoint.h"

namespace Framework
{
    using TestingType = MousePosition;
}

Framework::MousePositionTesting::MousePositionTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    TestingType windowMousePosition{ hwnd };

    const auto point1 = windowMousePosition.GetMousePosition();
    windowMousePosition.SetMousePosition(point1);

    const auto point2 = windowMousePosition.GetMousePosition();

    ASSERT_EQUAL(point1, point2);
}
