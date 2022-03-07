// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:53)

#include "StaticTestIntersectorLine2ClassifyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2ClassifyDetail.h"

#include "Mathematics/Algebra/Vector2Tools.h"
#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorLine2Classify<float>;
    template class StaticTestIntersectorLine2Classify<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorLine2ClassifyTesting)

void Mathematics::StaticTestIntersectorLine2ClassifyTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}
#include SYSTEM_WARNING_DISABLE(26496)

void Mathematics::StaticTestIntersectorLine2ClassifyTesting ::LineTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F lhsOrigin(randomDistribution(generator),
                           randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator),
                              randomDistribution(generator));
        Vector2F rhsOrigin(randomDistribution(generator),
                           randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator),
                              randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        StaticTestIntersectorLine2Classify<float> firstClassify(lhsOrigin, lhsDirection, lhsOrigin, lhsDirection);

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);

        StaticTestIntersectorLine2Classify<float> secondClassify(lhsOrigin, lhsDirection, rhsOrigin, lhsDirection);

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);

        StaticTestIntersectorLine2Classify<float> thirdClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection);

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + thirdClassify.GetParameter0() * lhsDirection,
                                        rhsOrigin + thirdClassify.GetParameter1() * rhsDirection, 1e-4f);
    }
}
