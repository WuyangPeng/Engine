///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:01)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MemorySetTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemorySetTesting;
        using ParentType = UnitTest;

    public:
        explicit MemorySetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MemorySetTest();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H