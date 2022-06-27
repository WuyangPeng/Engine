///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:18)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowInstanceParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowInstanceParameterTesting;
        using ParentType = UnitTest;
        using HInstance = System::WindowsHInstance;

    public:
        WindowInstanceParameterTesting(const OStreamShared& osPtr, HInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ValueTest();

        void DoRunUnitTest() final;

    private:
        HInstance instance;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
