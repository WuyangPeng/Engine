///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:53)

#include "StaticTestIntersectorLine2ClassifyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2ClassifyDetail.h"

#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorLine2Classify<float>;
    template class StaticTestIntersectorLine2Classify<double>;
}

Mathematics::StaticTestIntersectorLine2ClassifyTesting::StaticTestIntersectorLine2ClassifyTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticTestIntersectorLine2ClassifyTesting)

void Mathematics::StaticTestIntersectorLine2ClassifyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticTestIntersectorLine2ClassifyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::StaticTestIntersectorLine2ClassifyTesting::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F lhsOrigin(randomDistribution(generator),
                                 randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator),
                              randomDistribution(generator));
        const Vector2F rhsOrigin(randomDistribution(generator),
                                 randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator),
                              randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        StaticTestIntersectorLine2Classify<float> firstClassify(lhsOrigin, lhsDirection, lhsOrigin, lhsDirection);

        ASSERT_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);

        StaticTestIntersectorLine2Classify<float> secondClassify(lhsOrigin, lhsDirection, rhsOrigin, lhsDirection);

        ASSERT_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);

        StaticTestIntersectorLine2Classify<float> thirdClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection);

        ASSERT_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate,
                                        lhsOrigin + thirdClassify.GetParameter0() * lhsDirection,
                                        rhsOrigin + thirdClassify.GetParameter1() * rhsDirection,
                                        1e-3f);
    }
}
