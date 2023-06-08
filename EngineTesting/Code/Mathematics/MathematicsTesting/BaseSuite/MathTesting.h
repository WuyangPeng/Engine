///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.8.0.8 (2022/06/08 10:44)

#ifndef MATHEMATICS_BASE_SUITE_MATH_TESTING_H
#define MATHEMATICS_BASE_SUITE_MATH_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class MathTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MathTesting;
        using ParentType = UnitTest;

    public:
        explicit MathTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstantTest();
        void TrigonometricTest();
        void BaseMathTest();
        void LogTest();
        void PowTest();
        void TruncationTest();
        void ApproximateTest();

        // Constant≤‚ ‘
        void FloatConstantTest();
        void DoubleConstantTest();

        // Trigonometric≤‚ ‘
        void FloatTrigonometricTest();
        void DoubleTrigonometricTest();
        void TrigonometricBoundaryTest();

        // BaseMath≤‚ ‘
        void FloatBaseMathTest();
        void DoubleBaseMathTest();
        void BaseMathBoundaryTest();

        // Log≤‚ ‘
        void FloatLogTest();
        void DoubleLogTest();

        // Pow≤‚ ‘
        void FloatPowTest();
        void DoublePowTest();
        void PowBoundaryTest();

        // Truncation≤‚ ‘
        void FloatTruncationTest();
        void DoubleTruncationTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_MATH_TESTING_H