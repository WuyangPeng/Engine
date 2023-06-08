///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 11:22)

#include "DynamicIntersectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/DynamicIntersectorTestDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

namespace Mathematics
{
    template class DynamicIntersectorTest<float, Vector2>;
    template class DynamicIntersectorTest<double, Vector2>;
    template class DynamicIntersectorTest<float, Vector3>;
    template class DynamicIntersectorTest<double, Vector3>;
}

Mathematics::DynamicIntersectorTesting::DynamicIntersectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DynamicIntersectorTesting)

void Mathematics::DynamicIntersectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DynamicIntersectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest);
}

void Mathematics::DynamicIntersectorTesting::IntersectionTypeTest()
{
    using System::operator++;

    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
        {
            auto tMax = randomDistribution(generator);
            const Vector3D lhsVelocity(randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator));
            const Vector3D rhsVelocity(randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator));
            const auto contactTime = MathD::FAbs(randomDistribution(generator));

            DynamicIntersectorTest<double, Vector3> intersectorTest(tMax, lhsVelocity, rhsVelocity, IntersectionType(i), contactTime, 1e-10);

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

            ASSERT_APPROXIMATE(intersectorTest.GetTMax(), tMax, 1e-10);
            ASSERT_APPROXIMATE(intersectorTest.GetContactTime(), contactTime, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, intersectorTest.GetLhsVelocity(), lhsVelocity, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, intersectorTest.GetRhsVelocity(), rhsVelocity, 1e-10);
        }
    }
}
