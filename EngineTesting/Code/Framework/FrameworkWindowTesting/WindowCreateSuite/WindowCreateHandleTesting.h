///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:09)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowCreateHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateHandleTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;
        using HInstance = System::WindowsHInstance;

    public:
        WindowCreateHandleTesting(const OStreamShared& stream, HInstance instance, HWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CreateTest();

        void DoRunUnitTest() final;

    private:
        HInstance instance;
        HWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
