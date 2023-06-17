///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:25)

#ifndef MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H
#define MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class FastTrigonometricTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = FastTrigonometricTesting;
        using ParentType = UnitTest;

    public:
        explicit FastTrigonometricTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void FastSinTest();
        void FloatFastSinTest();
        void DoubleFastSinTest();

        void FastCosTest();
        void FloatFastCosTest();
        void DoubleFastCosTest();

        void FastTanTest();
        void FloatFastTanTest();
        void DoubleFastTanTest();

        void FastInvSinTest();
        void FloatFastInvSinTest();
        void DoubleFastInvSinTest();

        void FastInvCosTest();
        void FloatFastInvCosTest();
        void DoubleFastInvCosTest();

        void FastInvTanTest();
        void FloatFastInvTanTest();
        void DoubleFastInvTanTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H