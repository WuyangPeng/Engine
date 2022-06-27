///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 13:53)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H

#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowRegisterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowRegisterTesting;
        using ParentType = UnitTest;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowRegisterTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void RegisterTest();

    private:
        HInstance instance;
        int count;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
