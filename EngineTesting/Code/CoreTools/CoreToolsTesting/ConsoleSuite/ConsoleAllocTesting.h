///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:33)

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
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_ALLOC_TESTING_H
