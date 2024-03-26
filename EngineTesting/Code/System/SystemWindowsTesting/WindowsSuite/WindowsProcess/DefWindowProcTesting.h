/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:15)

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
        explicit DefWindowProcTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefWindowProcTest();

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DEF_WINDOW_PROC_TESTING_H