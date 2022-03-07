// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:52)

#include "StaticTestIntersectorBox2Box2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorBox2Box2Detail.h"

#include "Mathematics/Algebra/Vector2Tools.h"
#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorBox2Box2<float>;
    template class StaticTestIntersectorBox2Box2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorBox2Box2Testing)

void Mathematics::StaticTestIntersectorBox2Box2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::StaticTestIntersectorBox2Box2Testing ::BoxTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F lhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        Vector2F rhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        Vector2F lhsFirstAxis(randomDistribution(generator),
                              randomDistribution(generator));

        Vector2F rhsFirstAxis(randomDistribution(generator),
                              randomDistribution(generator));

        lhsFirstAxis.Normalize();
        rhsFirstAxis.Normalize();

        float lhsFirstExtent = MathF::FAbs(randomDistribution(generator));
        float rhsFirstExtent = MathF::FAbs(randomDistribution(generator));

        Vector2F lhsSecondAxis(randomDistribution(generator),
                               randomDistribution(generator));

        Vector2F rhsSecondAxis(randomDistribution(generator),
                               randomDistribution(generator));

        lhsSecondAxis.Normalize();
        rhsSecondAxis.Normalize();

        float lhsSecondExtent = MathF::FAbs(randomDistribution(generator));
        float rhsSecondExtent = MathF::FAbs(randomDistribution(generator));

        Box2F lhsBox(lhsCenter, lhsFirstAxis, lhsSecondAxis, lhsFirstExtent, lhsSecondExtent);
        Box2F rhsBox(rhsCenter, rhsFirstAxis, rhsSecondAxis, rhsFirstExtent, rhsSecondExtent);

        StaticTestIntersectorBox2Box2<float> intersector(lhsBox, rhsBox);

        Vector2F boxCentersDifference = rhsCenter - lhsCenter;

        float absA0DotB0 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, rhsFirstAxis));
        float absA0DotB1 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, rhsSecondAxis));
        float absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, boxCentersDifference));

        if (lhsFirstExtent + rhsFirstExtent * absA0DotB0 + rhsSecondExtent * absA0DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        float absA1DotB0 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, rhsFirstAxis));
        float absA1DotB1 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, rhsSecondAxis));
        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, boxCentersDifference));

        if (lhsSecondExtent + rhsFirstExtent * absA1DotB0 + rhsSecondExtent * absA1DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(rhsFirstAxis, boxCentersDifference));

        if (rhsFirstExtent + lhsFirstExtent * absA0DotB0 + lhsSecondExtent * absA1DotB0 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(rhsSecondAxis, boxCentersDifference));

        if (rhsSecondExtent + lhsFirstExtent * absA0DotB1 + lhsSecondExtent * absA1DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        ASSERT_TRUE(intersector.IsIntersection());
    }
}
