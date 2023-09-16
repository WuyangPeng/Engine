///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:19)

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