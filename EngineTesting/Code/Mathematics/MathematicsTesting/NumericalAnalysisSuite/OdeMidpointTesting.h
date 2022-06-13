///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 15:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_MIDPOINT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_MIDPOINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
    class OdeMidpointTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OdeMidpointTesting);

        NODISCARD int GetDimension() const noexcept;

    private:
        void MainTest();
        void SolverTest();

        void DoRunUnitTest() override;

        NODISCARD static std::vector<double> OdeMidpointFunction(double tIn, const std::vector<double>& xIn, const OdeMidpointTesting* odeEulerTesting);

    private:
        int dimension;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_MIDPOINT_TESTING_H