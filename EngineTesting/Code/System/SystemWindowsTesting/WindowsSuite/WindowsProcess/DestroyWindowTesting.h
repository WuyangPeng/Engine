/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:15)

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
        DestroyWindowTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DestroyWindowTest();

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DESTROY_WINDOW_TESTING_H