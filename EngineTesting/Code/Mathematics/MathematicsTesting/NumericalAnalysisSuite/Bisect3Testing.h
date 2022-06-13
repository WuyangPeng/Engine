///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Bisect3Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Bisect3Testing);

    private:
        void MainTest();
        void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();

        void DoRunUnitTest() override;

        NODISCARD constexpr static double FirstEquation(double x, double y, double z)
        {
            return 1.0 * x + 1.0 * y - 2.0 * z + 1.0;
        }

        NODISCARD constexpr static double SecondEquation(double x, double y, double z)
        {
            return 2.0 * x + 3.0 * y - 1.0 * z - 1.0;
        }

        NODISCARD constexpr static double ThirdEquation(double x, double y, double z)
        {
            return 3.0 * x + 1.0 * y - 2.0 * z - 1.0;
        }
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_TESTING_H