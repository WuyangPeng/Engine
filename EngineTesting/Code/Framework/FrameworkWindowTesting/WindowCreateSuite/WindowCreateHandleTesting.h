///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 15:48)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowCreateHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateHandleTesting;
        using ParentType = UnitTest;

        using WindowsHWnd = System::WindowsHWnd;
        using WindowsHInstance = System::WindowsHInstance;

    public:
        WindowCreateHandleTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CreateTest();

        void DoRunUnitTest() override;

    private:
        WindowsHInstance instance;
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
