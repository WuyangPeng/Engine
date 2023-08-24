///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 14:47)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowProcessHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowProcessHandleTesting;
        using ParentType = UnitTest;

        using WindowsHWnd = System::WindowsHWnd;

    public:
        explicit WindowProcessHandleTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void BaseTest();
        void ClassNameTest();
        void HWndTest();

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
