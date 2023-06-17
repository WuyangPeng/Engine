///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Bisect3CalculateTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Bisect3CalculateTesting;
        using ParentType = UnitTest;

    public:
        explicit Bisect3CalculateTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void HaveSolutionTest() noexcept;
        void NoSolutionTest() noexcept;
        void UnknownTest() noexcept;

        void DoRunUnitTest() override;

        NODISCARD constexpr static float FirstEquation(float x, float y, float z)
        {
            return 1.0f * x + 1.0f * y - 2.0f * z + 1.0f;
        }

        NODISCARD constexpr static float SecondEquation(float x, float y, float z)
        {
            return 2.0f * x + 3.0f * y - 1.0f * z - 1.0f;
        }

        NODISCARD constexpr static float ThirdEquation(float x, float y, float z)
        {
            return 3.0f * x + 1.0f * y - 2.0f * z - 1.0f;
        }
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H