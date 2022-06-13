///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:03)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
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
        void DoRunUnitTest() final;
        void MainTest();

        void HandleTest();

    private:
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H