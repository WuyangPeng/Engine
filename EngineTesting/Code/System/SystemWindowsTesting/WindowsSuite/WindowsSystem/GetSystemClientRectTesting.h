///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 19:45)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_SYSTEM_CLIENT_RECT_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_SYSTEM_CLIENT_RECT_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetSystemClientRectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSystemClientRectTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSystemClientRectTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetSystemClientRectTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_SYSTEM_CLIENT_RECT_TESTING_H