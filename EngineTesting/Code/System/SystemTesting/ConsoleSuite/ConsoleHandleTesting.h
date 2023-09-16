///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:31)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ConsoleHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void HandleTest();
        void DoHandleTest(StandardHandle standardHandle);
        void InputHandleTest(StandardHandle standardHandle);
        void OutputHandleTest(StandardHandle standardHandle);
        void SetStandardHandleTest(StandardHandle standardHandle, WindowsHandle windowsHandle);

        void PreviousHandleTest(StandardHandle standardHandle, WindowsHandle defaultHandle, WindowsHandle windowsHandle);

    private:
        using StandardHandleContainer = std::vector<StandardHandle>;

    private:
        StandardHandleContainer standardHandles;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H