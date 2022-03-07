// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:53)

#include "StaticTestIntersectorLine2Ray2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Ray2Detail.h"

#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorLine2Ray2<float>;
    template class StaticTestIntersectorLine2Ray2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorLine2Ray2Testing)

void Mathematics::StaticTestIntersectorLine2Ray2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::StaticTestIntersectorLine2Ray2Testing ::RayTest()
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

        StaticTestIntersectorLine2Ray2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);

        StaticTestIntersectorLine2Ray2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticTestIntersectorLine2Ray2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), INT_MAX);

        StaticTestIntersectorLine2Ray2<float> fourthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin + lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), INT_MAX);

        StaticTestIntersectorLine2Ray2<float> fifthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin - lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), INT_MAX);

        StaticTestIntersectorLine2Ray2<float> sixthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(rhsOrigin, rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                  true);

        if (0.0f <= seventhClassify.GetParameter1())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
        }
    }
}
