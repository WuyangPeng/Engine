/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:14)

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
        WindowsCreateMenuTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MenuTest();
        void DoMenuTest(WindowsHWnd systemWindow);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_MENU_TESTING_H