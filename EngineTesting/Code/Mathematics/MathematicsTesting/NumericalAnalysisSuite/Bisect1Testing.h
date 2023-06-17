///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Bisect1Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Bisect1Testing;
        using ParentType = UnitTest;

    public:
        explicit Bisect1Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();

        void DoRunUnitTest() override;

        NODISCARD constexpr static double FirstEquation(double value)
        {
            return 5.0 * value * value + 4.0 * value - 3.0;
        }

        NODISCARD constexpr static float SecondEquation(float value)
        {
            return 2.0f * value * value + 2.0f * value - 1.0f;
        }
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H