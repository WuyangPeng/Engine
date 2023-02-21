///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:11)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SevenModElevenCheckSumTesting : public UnitTest
    {
    public:
        using ClassType = SevenModElevenCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit SevenModElevenCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void SumTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SEVEN_MOD_ELEVEN_CHECK_SUM_TESTING_H
