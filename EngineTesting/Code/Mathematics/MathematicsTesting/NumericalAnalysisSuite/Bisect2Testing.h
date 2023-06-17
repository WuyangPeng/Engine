///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Bisect2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Bisect2Testing;
        using ParentType = UnitTest;

    public:
        explicit Bisect2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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