///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 11:29)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class IntegerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = IntegerTesting;
        using ParentType = UnitTest;

    public:
        explicit IntegerTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void CalculateTest();
        void CompareTest();
        void UtilitiesTest();

        // Construction测试
        void PositiveTest();
        void NegativeTest();
        void ZeroTest();

        // Calculate测试
        void ReverseTest();
        void AbsoluteValueTest();
        void AddTest();
        void MinusTest();
        void MultiplyTest();
        void DivideTest();
        void LeftShiftTest();
        void RightShiftTest();
        void SignTest();

        // Utilities测试
        void BlockTest();
        void BitTest();
        void ConversionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H