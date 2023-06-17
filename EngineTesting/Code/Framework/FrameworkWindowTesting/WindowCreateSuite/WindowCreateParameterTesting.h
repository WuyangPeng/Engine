///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:09)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowCreateParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateParameterTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;

    public:
        WindowCreateParameterTesting(const OStreamShared& stream, HWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() final;

        void ValueTest();

    private:
        HWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H
