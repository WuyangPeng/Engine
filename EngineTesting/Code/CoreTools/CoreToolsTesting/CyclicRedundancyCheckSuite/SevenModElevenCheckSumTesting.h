/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:08)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SevenModElevenCheckSumTesting final : public UnitTest
    {
    public:
        using ClassType = SevenModElevenCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit SevenModElevenCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SumTest();
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H
