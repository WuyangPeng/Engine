///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 10:44)

#ifndef MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H
#define MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class RandomTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RandomTesting);

    private:
        void MainTest();

        // Random测试
        void FloatRandomTest();
        void DoubleRandomTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H