///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:29)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowApplicationInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowApplicationInformationTesting;
        using ParentType = UnitTest;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowApplicationInformationTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void InformationTest();
        void AllowResizeTest();
        void NotAllowedResizeTest();
        void RendererParameterTest();

    private:
        HInstance instance;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H