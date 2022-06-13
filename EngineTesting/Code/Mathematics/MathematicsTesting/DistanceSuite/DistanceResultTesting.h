///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 11:00)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_RESULT_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_RESULT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class DistanceResultTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistanceResultTesting);

    private:
        void MainTest();
        void BaseTest();
        void ContactTimeTest();
        void ClosestPointsTest();
        void MultipleClosestPointsTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_RESULT_TESTING_H