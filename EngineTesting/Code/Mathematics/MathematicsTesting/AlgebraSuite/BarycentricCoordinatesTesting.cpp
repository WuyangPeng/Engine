///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:26)

#include "BarycentricCoordinatesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/BarycentricCoordinatesDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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
    const BarycentricCoordinates<float, 3> firstBarycentricCoordinates;

    ASSERT_FALSE(firstBarycentricCoordinates.IsBarycentricCoordinatesValid());

    const BarycentricCoordinates<double, 3> secondBarycentricCoordinates{ true, BarycentricCoordinates<double, 3>::Tuple(0.1, 0.4, 0.5) };

    ASSERT_APPROXIMATE(secondBarycentricCoordinates[0], 0.1, 1e-10);
    ASSERT_APPROXIMATE(secondBarycentricCoordinates[1], 0.4, 1e-10);
    ASSERT_APPROXIMATE(secondBarycentricCoordinates[2], 0.5, 1e-10);
}

void Mathematics::BarycentricCoordinatesTesting::BarycentricCoordinates4DTest()
{
    const BarycentricCoordinates<double, 4> firstBarycentricCoordinates;

    ASSERT_FALSE(firstBarycentricCoordinates.IsBarycentricCoordinatesValid());

    const BarycentricCoordinates<float, 4> secondBarycentricCoordinates{ true, BarycentricCoordinates<float, 4>::Tuple(0.1f, 0.4f, 0.3f, 0.2f) };

    ASSERT_APPROXIMATE(secondBarycentricCoordinates[0], 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondBarycentricCoordinates[1], 0.4f, 1e-8f);
    ASSERT_APPROXIMATE(secondBarycentricCoordinates[2], 0.3f, 1e-8f);
    ASSERT_APPROXIMATE(secondBarycentricCoordinates[3], 0.2f, 1e-8f);
}
