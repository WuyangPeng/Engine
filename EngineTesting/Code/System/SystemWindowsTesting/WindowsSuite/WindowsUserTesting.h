///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 20:18)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_USER_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_USER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsUserTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsUserTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsUserTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MessageTest();
        void HwndTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_USER_TESTING_H