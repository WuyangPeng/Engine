///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 14:24)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

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
