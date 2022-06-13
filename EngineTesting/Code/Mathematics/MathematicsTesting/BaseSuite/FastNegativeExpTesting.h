///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 10:42)

#ifndef MATHEMATICS_BASE_SUITE_FAST_NEGATIVE_EXP_TESTING_H
#define MATHEMATICS_BASE_SUITE_FAST_NEGATIVE_EXP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class FastNegativeExpTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FastNegativeExpTesting);

    private:
        void MainTest();

        void FloatFastExpTest();
        void DoubleFastExpTest();
        void FloatFastExpBoundaryTest();
        void DoubleFastExpBoundaryTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_FAST_NEGATIVE_EXP_TESTING_H