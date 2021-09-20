///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/07 10:56)

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
        explicit DestroyWindowTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DestroyWindowTest();

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_DESTROY_WINDOW_TESTING_H