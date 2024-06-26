/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:28)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class HeapAllocateTesting final : public UnitTest
    {
    public:
        using ClassType = HeapAllocateTesting;
        using ParentType = UnitTest;

    public:
        explicit HeapAllocateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto size = 20;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CharTest();
        void DoubleTest();
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
