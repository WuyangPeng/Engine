///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:31)

#ifndef CORE_TOOLS_CONSOLE_SUITE_CONSOLE_ALLOC_TESTING_H
#define CORE_TOOLS_CONSOLE_SUITE_CONSOLE_ALLOC_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConsoleAllocTesting final : public UnitTest
    {
    public:
        using ClassType = ConsoleAllocTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_ALLOC_TESTING_H
