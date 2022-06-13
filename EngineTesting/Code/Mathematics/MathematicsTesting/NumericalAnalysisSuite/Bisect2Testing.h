///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 14:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Bisect2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Bisect2Testing);

    private:
        void MainTest();
        void HaveSolutionTest() noexcept;
        void NoSolutionTest() noexcept;
        void UnknownTest() noexcept;

        void DoRunUnitTest() override;

        NODISCARD constexpr static double FirstEquation(double x, double y)
        {
            return 2.0 * x - 1.0 + 1.0 * y;
        }

        NODISCARD constexpr static double SecondEquation(double x, double y)
        {
            return 3.0 * x - 2.0 + 3.0 * y;
        }
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H