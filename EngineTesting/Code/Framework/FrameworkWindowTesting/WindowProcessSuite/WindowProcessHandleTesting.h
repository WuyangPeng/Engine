///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:09)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowProcessHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowProcessHandleTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;

    public:
        explicit WindowProcessHandleTesting(const OStreamShared& stream, HWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void BaseTest();
        void ClassNameTest();
        void HWndTest();

    private:
        HWnd hwnd;
    };
}

#endif  //FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
