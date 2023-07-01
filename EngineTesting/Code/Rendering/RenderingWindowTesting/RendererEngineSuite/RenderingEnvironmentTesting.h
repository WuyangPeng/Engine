///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:53)

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
        RenderingEnvironmentTesting(const OStreamShared& stream, HWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void RenderingEnvironmentTest();
        void GetRenderingDeviceTest();

    private:
        HWnd hWnd;
    };
}

#endif  // RENDERING_WINDOW_SUITE_RENDERING_ENVIRONMENT_TESTING_H
