// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class GaussianQuadratureTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(GaussianQuadratureTesting);

    private:
        void MainTest();

        void DoRunUnitTest() override;
        void ResultTest();

        static double Solution(double input, const GaussianQuadratureTesting* userData) noexcept;
        double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_GAUSSIAN_QUADRATURE_TESTING_H