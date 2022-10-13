///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/15 15:54)

#ifndef RENDERING_WINDOW_SUITE_RENDERING_ENVIRONMENT_TESTING_H
#define RENDERING_WINDOW_SUITE_RENDERING_ENVIRONMENT_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace RenderingWindowTesting
{
    class RenderingEnvironmentTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderingEnvironmentTesting;
        using ParentType = UnitTest;
        using HWnd = System::WindowsHWnd;

    public:
        RenderingEnvironmentTesting(const OStreamShared& stream, HWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void RenderingEnvironmentTest();
        void GetRenderingDeviceTest();

    private:
        HWnd hwnd;
    };
}

#endif  // RENDERING_WINDOW_SUITE_RENDERING_ENVIRONMENT_TESTING_H
