///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:10)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Vector3ToolsTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector3ToolsTesting);

    private:
        void MainTest();
        void DistanceTest();
        void ProductTest();
        void ProjectionTest();
        void ConversionTest();
        void CompareTest();
        void OtherCalculateTest();

        void DoRunUnitTest() override;

        NODISCARD constexpr static double Half(double value)
        {
            return value * 0.5;
        }
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H