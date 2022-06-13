///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 11:12)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class DistancePoint2Hyperbola2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistancePoint2Hyperbola2Testing);

    private:
        void MainTest();
        void BaseTest();
        void StaticTest();
        void DynamicTest();
        void DerivativeTest();
        void IntervalTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H