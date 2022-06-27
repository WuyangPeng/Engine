///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:30)

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
