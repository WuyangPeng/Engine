///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_MIDPOINT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_MIDPOINT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace Mathematics
{
    class OdeMidpointTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OdeMidpointTesting;
        using ParentType = UnitTest;

    public:
        explicit OdeMidpointTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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