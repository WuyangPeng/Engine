///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:24)

#include "HomogeneousPointTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class HomogeneousPoint<float>;
    template class HomogeneousPoint<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::HomogeneousPointTesting::HomogeneousPointTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, HomogeneousPointTesting)

void Mathematics::HomogeneousPointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::HomogeneousPointTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::HomogeneousPointTesting::ConstructionTest()
{
    HomogeneousPointF point0;

    ASSERT_APPROXIMATE(point0[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[3], 0.0f, 1e-8f);

    point0.SetX(1.0f);
    point0.SetY(2.0f);
    point0.SetW(4.0f);

    HomogeneousPointF point1(point0);

    ASSERT_APPROXIMATE(point1[0], 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(point1[1], 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(point1[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point1[3], 4.0f, 1e-8f);

    ASSERT_TRUE(Approximate(point0, point1, 1e-8f));

    HomogeneousPointD point2(3.0, 5.0, 6.0, 7.0);

    ASSERT_APPROXIMATE(point2[0], 3.0, 1e-10);
    ASSERT_APPROXIMATE(point2[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(point2[2], 6.0, 1e-10);
    ASSERT_APPROXIMATE(point2[3], 7.0, 1e-10);

    point1.SetX(11.0f);
    point1.SetY(12.0f);
    point1.SetZ(14.0f);

    ASSERT_FALSE(Approximate(point0, point1, 1e-8f));

    point0 = point1;

    ASSERT_APPROXIMATE(point0[0], 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], 14.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[3], 4.0f, 1e-8f);

    ASSERT_TRUE(Approximate(point0, point1, 1e-8f));
}

void Mathematics::HomogeneousPointTesting::AccessTest()
{
    HomogeneousPointF point0(1.0f, 2.0f, 0.0f, 4.0f);

    ASSERT_APPROXIMATE(point0[0], 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[3], 4.0f, 1e-8f);

    ASSERT_APPROXIMATE(point0.GetX(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetY(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetZ(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetW(), 4.0f, 1e-8f);

    point0.SetX(6.0f);
    point0.SetY(8.0f);
    point0.SetZ(2.0f);
    point0.SetW(9.0f);

    ASSERT_APPROXIMATE(point0.GetX(), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetY(), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetZ(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0.GetW(), 9.0f, 1e-8f);

    const HomogeneousPointD point1(5.0, 1.0, 3.0, 2.0);

    ASSERT_APPROXIMATE(point1[0], 5.0, 1e-10);
    ASSERT_APPROXIMATE(point1[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(point1[2], 3.0, 1e-10);
    ASSERT_APPROXIMATE(point1[3], 2.0, 1e-10);

    ASSERT_APPROXIMATE(point1.GetX(), 5.0, 1e-10);
    ASSERT_APPROXIMATE(point1.GetY(), 1.0, 1e-10);
    ASSERT_APPROXIMATE(point1.GetZ(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(point1.GetW(), 2.0, 1e-10);
}

void Mathematics::HomogeneousPointTesting::CompareTest()
{
    const HomogeneousPointF point0(1.0f, 2.0f, 0.0f, 4.0f);
    const HomogeneousPointF point1;

    ASSERT_FALSE(point0 == point1);
    ASSERT_TRUE(point0 != point1);

    ASSERT_FALSE(point0 < point1);
    ASSERT_TRUE(point0 > point1);
    ASSERT_FALSE(point0 <= point1);
    ASSERT_TRUE(point0 >= point1);

    ASSERT_TRUE(Approximate(point0, point0, 1e-8f));
    ASSERT_TRUE(Approximate(point1, point1, 1e-8f));
    ASSERT_FALSE(Approximate(point0, point1, 1e-8f));
}
