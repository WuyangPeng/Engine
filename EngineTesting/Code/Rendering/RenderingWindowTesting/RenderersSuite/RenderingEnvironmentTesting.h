///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/15 15:54)

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
