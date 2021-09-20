///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 13:30)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DEF_WINDOW_PROC_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DEF_WINDOW_PROC_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DefWindowProcTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DefWindowProcTesting;
        using ParentType = UnitTest;

    public:
        explicit DefWindowProcTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DefWindowProcTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DEF_WINDOW_PROC_TESTING_H