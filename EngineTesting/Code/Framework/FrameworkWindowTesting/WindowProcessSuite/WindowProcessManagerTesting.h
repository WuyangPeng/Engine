///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:08)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowProcessManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowProcessManagerTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;

    public:
        explicit WindowProcessManagerTesting(const OStreamShared& stream, HWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ManagerTest();
        void ClassNameTest();
        void SetMainWindow();

    private:
        HWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H