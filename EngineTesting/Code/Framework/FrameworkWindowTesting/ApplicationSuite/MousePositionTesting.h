///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 14:30)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class MousePositionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MousePositionTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;

    public:
        explicit MousePositionTesting(const OStreamShared& stream, HWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void WindowMousePositionTest();

    private:
        HWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H
