///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 15:49)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowInstanceParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowInstanceParameterTesting;
        using ParentType = UnitTest;

        using WindowsHInstance = System::WindowsHInstance;

    public:
        WindowInstanceParameterTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ValueTest();

        void DoRunUnitTest() override;

    private:
        WindowsHInstance instance;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
