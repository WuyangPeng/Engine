///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:51)

#include "IntersectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/IntersectorTestDetail.h"

namespace Mathematics
{
    template class IntersectorTest<float, Vector2>;
    template class IntersectorTest<double, Vector2>;
    template class IntersectorTest<float, Vector3>;
    template class IntersectorTest<double, Vector3>;
}

Mathematics::IntersectorTesting::IntersectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntersectorTesting)

void Mathematics::IntersectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntersectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest);
}

void Mathematics::IntersectorTesting::IntersectionTypeTest()
{
    using System::operator++;

    for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
    {
        IntersectorTest<float, Vector2> intersectorTest(IntersectionType(i), 1e-8f);

        ASSERT_ENUM_EQUAL(intersectorTest.GetIntersectionType(), IntersectionType(i));
        ASSERT_APPROXIMATE(intersectorTest.GetEpsilon(), 1e-8f, 1e-8f);

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
