///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:29)

#include "MousePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
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
