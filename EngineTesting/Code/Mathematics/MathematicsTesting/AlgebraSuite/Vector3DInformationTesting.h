///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:09)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector3InformationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector3InformationTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector3InformationTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DimensionTest();
        void AxesAlignBoundingBoxTest();
        void DirectionTest();
        void ExtremeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H