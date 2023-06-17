///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:25)

#ifndef MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H
#define MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class BitHacksTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BitHacksTesting;
        using ParentType = UnitTest;

    public:
        explicit BitHacksTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void IsPowerOfTwoTest();
        void Log2OfPowerOfTwoTest();
        void ScaledFloatToIntTest();

        // IsPowerOfTwo测试
        void SignIntIsPowerOfTwoTrueTest();
        void UnsignIntIsPowerOfTwoTrueTest();
        void SignIntIsPowerOfTwoFalseTest();
        void UnsignIntIsPowerOfTwoFalseTest();

        // Log2OfPowerOfTwo测试
        void FixedValueLog2OfPowerOfTwoTest();
        void SignIntLog2OfPowerOfTwoTest();
        void UnsignIntLog2OfPowerOfTwoTest();

        // ScaledFloatToInt测试
        void ScaledFloatToIntMinTest();
        void ScaledFloatToIntMaxTest();
        void ScaledFloatToIntRandomTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H