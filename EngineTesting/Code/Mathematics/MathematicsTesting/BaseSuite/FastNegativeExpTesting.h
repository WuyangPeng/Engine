///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 10:42)

#ifndef MATHEMATICS_BASE_SUITE_FAST_NEGATIVE_EXP_TESTING_H
#define MATHEMATICS_BASE_SUITE_FAST_NEGATIVE_EXP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class FastNegativeExpTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = FastNegativeExpTesting;
        using ParentType = UnitTest;

    public:
        explicit FastNegativeExpTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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