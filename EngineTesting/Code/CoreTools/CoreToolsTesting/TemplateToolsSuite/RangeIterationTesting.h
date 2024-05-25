/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 11:08)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_RANGE_ITERATION_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_RANGE_ITERATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RangeIterationTesting final : public UnitTest
    {
    public:
        using ClassType = RangeIterationTesting;
        using ParentType = UnitTest;

    public:
        explicit RangeIterationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RangeIterationTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_RANGE_ITERATION_TESTING_H