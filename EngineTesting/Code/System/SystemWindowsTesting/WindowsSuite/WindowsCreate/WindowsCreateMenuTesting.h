///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 19:46)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_MENU_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_MENU_TESTING_H

#include "CreateWindowTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WindowsCreateMenuTesting final : public CreateWindowTestingBase
    {
    public:
        using ClassType = WindowsCreateMenuTesting;
        using ParentType = CreateWindowTestingBase;

    public:
        explicit WindowsCreateMenuTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MenuTest();

        void DoMenuTest(WindowsHWnd systemWindow);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_MENU_TESTING_H