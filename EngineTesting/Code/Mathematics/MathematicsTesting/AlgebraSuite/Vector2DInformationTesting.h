///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 11:13)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector2InformationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector2InformationTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector2InformationTesting(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H