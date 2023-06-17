///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class GaussianQuadratureTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = GaussianQuadratureTesting;
        using ParentType = UnitTest;

    public:
        explicit GaussianQuadratureTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;
        void ResultTest();

        NODISCARD static double Solution(double input, const GaussianQuadratureTesting* userData) noexcept;
        NODISCARD double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H