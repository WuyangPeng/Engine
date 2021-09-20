///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 11:43)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_VALIDATE_RECT_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_VALIDATE_RECT_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ValidateRectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ValidateRectTesting;
        using ParentType = UnitTest;

    public:
        explicit ValidateRectTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ValidateRectTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_VALIDATE_RECT_TESTING_H