///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:41)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsCreateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsCreateTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsCreateTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateSystemWindowTest();
        void GetHInstanceTest();
        void MenuTest();

    private:
        WindowsHInstance instance;
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_WINDOW_CREATE_TESTING_H