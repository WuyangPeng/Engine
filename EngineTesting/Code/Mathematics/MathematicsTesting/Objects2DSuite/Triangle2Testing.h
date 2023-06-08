///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 13:48)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_TRIANGLE2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_TRIANGLE2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Triangle2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Triangle2Testing;
        using ParentType = UnitTest;

    public:
        explicit Triangle2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void TriangleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_TRIANGLE2_TESTING_H