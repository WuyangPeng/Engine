// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:52)

#include "StaticFindIntersectorRay2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorRay2Segment2Detail.h"

#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include <random>

namespace Mathematics
{
    template class StaticFindIntersectorRay2Segment2<float>;
    template class StaticFindIntersectorRay2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorRay2Segment2Testing)

void Mathematics::StaticFindIntersectorRay2Segment2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorRay2Segment2Testing ::SegmentTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D lhsOrigin(randomDistribution(generator),
                                randomDistribution(generator));
        FloatVector2D lhsDirection(randomDistribution(generator),
                                   randomDistribution(generator));
        FloatVector2D rhsOrigin(randomDistribution(generator),
                                randomDistribution(generator));
        FloatVector2D rhsDirection(randomDistribution(generator),
                                   randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        float extent = FloatMath::FAbs(randomDistribution(generator));

        if (extent < 1.0f)
        {
            extent = 1.5f;
        }

        FloatStaticFindIntersectorRay2Segment2 firstClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(lhsOrigin, lhsOrigin + extent * lhsDirection, 1e-5f));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin, firstClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin + extent * lhsDirection, firstClassify.GetPoint(1), 1e-5f);

        FloatStaticFindIntersectorRay2Segment2 secondClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        FloatStaticFindIntersectorRay2Segment2 thirdClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin, thirdClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin + extent * lhsDirection, thirdClassify.GetPoint(1), 1e-6f);

        FloatStaticFindIntersectorRay2Segment2 fifthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(lhsOrigin - lhsDirection, lhsOrigin - lhsDirection - extent * lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        FloatStaticFindIntersectorRay2Segment2 sixthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, rhsDirection));

        FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                true);

        if (0.0f <= seventhClassify.GetParameter0() &&
            FloatMath::FAbs(seventhClassify.GetParameter1()) <= sixthClassify.GetSegment().GetExtent())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
            ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin + seventhClassify.GetParameter0() * lhsDirection, sixthClassify.GetPoint(0), 1e-6f);
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
        }
    }
}
