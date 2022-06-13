///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 11:25)

#include "StaticIntersectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/StaticIntersectorTestDetail.h"

namespace Mathematics
{
    template class StaticIntersectorTest<float, Vector2>;
    template class StaticIntersectorTest<double, Vector2>;
    template class StaticIntersectorTest<float, Vector3>;
    template class StaticIntersectorTest<double, Vector3>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticIntersectorTesting)

void Mathematics::StaticIntersectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest);
}

void Mathematics::StaticIntersectorTesting::IntersectionTypeTest()
{
    for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
    {
        StaticIntersectorTest<double, Vector3> intersectorTest(IntersectionType(i), 1e-10);

        ASSERT_ENUM_EQUAL(intersectorTest.GetIntersectionType(), IntersectionType(i));
        ASSERT_APPROXIMATE(intersectorTest.GetEpsilon(), 1e-10, 1e-10);

        if (intersectorTest.GetIntersectionType() == IntersectionType::Empty)
        {
            ASSERT_FALSE(intersectorTest.IsIntersection());
        }
        else
        {
            ASSERT_TRUE(intersectorTest.IsIntersection());
        }
    }
}
