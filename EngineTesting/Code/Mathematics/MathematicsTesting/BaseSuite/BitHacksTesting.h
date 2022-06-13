///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 10:42)

#ifndef MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H
#define MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class BitHacksTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BitHacksTesting);

    private:
        void MainTest();
        void IsPowerOfTwoTest();
        void Log2OfPowerOfTwoTest();
        void ScaledFloatToIntTest();

        // IsPowerOfTwo����
        void SignIntIsPowerOfTwoTrueTest();
        void UnsignIntIsPowerOfTwoTrueTest();
        void SignIntIsPowerOfTwoFalseTest();
        void UnsignIntIsPowerOfTwoFalseTest();

        // Log2OfPowerOfTwo����
        void FixedValueLog2OfPowerOfTwoTest();
        void SignIntLog2OfPowerOfTwoTest();
        void UnsignIntLog2OfPowerOfTwoTest();

        // ScaledFloatToInt����
        void ScaledFloatToIntMinTest();
        void ScaledFloatToIntMaxTest();
        void ScaledFloatToIntRandomTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H