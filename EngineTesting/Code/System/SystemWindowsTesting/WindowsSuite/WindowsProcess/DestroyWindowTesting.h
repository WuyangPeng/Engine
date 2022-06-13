///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:39)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DESTROY_WINDOW_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DESTROY_WINDOW_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DestroyWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DestroyWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit DestroyWindowTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DestroyWindowTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DESTROY_WINDOW_TESTING_H