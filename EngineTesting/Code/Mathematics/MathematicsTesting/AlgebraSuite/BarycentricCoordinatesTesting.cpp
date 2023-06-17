///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:20)

#include "BarycentricCoordinatesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BarycentricCoordinatesDetail.h"

namespace Mathematics
{
    template class BarycentricCoordinates<float, 3>;
    template class BarycentricCoordinates<double, 3>;
    template class BarycentricCoordinates<float, 4>;
    template class BarycentricCoordinates<double, 4>;
}

Mathematics::BarycentricCoordinatesTesting::BarycentricCoordinatesTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BarycentricCoordinatesTesting)

void Mathematics::BarycentricCoordinatesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BarycentricCoordinatesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BarycentricCoordinates3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BarycentricCoordinates4DTest);
}

void Mathematics::BarycentricCoordinatesTesting::BarycentricCoordinates3DTest()
{
    const BarycentricCoordinates<float, 3> barycentricCoordinates0{};

    ASSERT_FALSE(barycentricCoordinates0.IsBarycentricCoordinatesValid());

    const BarycentricCoordinates<double, 3> barycentricCoordinates1{ true, BarycentricCoordinates<double, 3>::Tuple(0.1, 0.4, 0.5) };

    ASSERT_APPROXIMATE(barycentricCoordinates1[0], 0.1, 1e-10);
    ASSERT_APPROXIMATE(barycentricCoordinates1[1], 0.4, 1e-10);
    ASSERT_APPROXIMATE(barycentricCoordinates1[2], 0.5, 1e-10);
}

void Mathematics::BarycentricCoordinatesTesting::BarycentricCoordinates4DTest()
{
    const BarycentricCoordinates<double, 4> barycentricCoordinates0;

    ASSERT_FALSE(barycentricCoordinates0.IsBarycentricCoordinatesValid());

    const BarycentricCoordinates<float, 4> barycentricCoordinates1{ true, BarycentricCoordinates<float, 4>::Tuple(0.1f, 0.4f, 0.3f, 0.2f) };

    ASSERT_APPROXIMATE(barycentricCoordinates1[0], 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(barycentricCoordinates1[1], 0.4f, 1e-8f);
    ASSERT_APPROXIMATE(barycentricCoordinates1[2], 0.3f, 1e-8f);
    ASSERT_APPROXIMATE(barycentricCoordinates1[3], 0.2f, 1e-8f);
}
