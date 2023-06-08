///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class BarycentricCoordinatesTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BarycentricCoordinatesTesting;
        using ParentType = UnitTest;

    public:
        explicit BarycentricCoordinatesTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BarycentricCoordinates3DTest();
        void BarycentricCoordinates4DTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H