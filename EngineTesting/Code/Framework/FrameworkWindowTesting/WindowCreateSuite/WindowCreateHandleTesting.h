///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 14:25)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowCreateHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateHandleTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;
        using HInstance = System::WindowsHInstance;

    public:
        WindowCreateHandleTesting(const OStreamShared& stream, HInstance instance, HWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CreateTest();

        void DoRunUnitTest() final;

    private:
        HInstance instance;
        HWnd hwnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
