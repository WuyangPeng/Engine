///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:55)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H

#include "System/Windows/WindowsProcess.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowRegisterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowRegisterTesting;
        using ParentType = UnitTest;

        using WindowsHInstance = System::WindowsHInstance;

    public:
        explicit WindowRegisterTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void RegisterTest();

    private:
        WindowsHInstance instance;
        int count;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
