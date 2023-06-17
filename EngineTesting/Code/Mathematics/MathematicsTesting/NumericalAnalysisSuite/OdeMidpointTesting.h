///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:57)

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