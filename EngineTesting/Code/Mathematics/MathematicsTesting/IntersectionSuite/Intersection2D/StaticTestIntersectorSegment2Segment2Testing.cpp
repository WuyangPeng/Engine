// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/30 18:54)

#include "StaticTestIntersectorSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorSegment2Segment2Detail.h"

#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorSegment2Segment2<float>;
    template class StaticTestIntersectorSegment2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorSegment2Segment2Testing)

void Mathematics::StaticTestIntersectorSegment2Segment2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticTestIntersectorSegment2Segment2Testing ::SegmentTest()
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

        float firstExtent = FloatMath::FAbs(randomDistribution(generator));
        float secondExtent = FloatMath::FAbs(randomDistribution(generator));

        FloatStaticTestIntersectorSegment2Segment2 firstClassify(FloatSegment2(firstExtent, lhsOrigin, lhsDirection), FloatSegment2(firstExtent, lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);

        FloatStaticTestIntersectorSegment2Segment2 secondClassify(FloatSegment2(firstExtent, lhsOrigin, lhsDirection), FloatSegment2(firstExtent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        FloatStaticTestIntersectorSegment2Segment2 thirdClassify(FloatSegment2(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), FloatSegment2(lhsOrigin, lhsOrigin - secondExtent * lhsDirection), 1e-5f);

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        FloatStaticTestIntersectorSegment2Segment2 fourthClassify(FloatSegment2(firstExtent, lhsOrigin, lhsDirection), FloatSegment2(secondExtent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);

        FloatStaticTestIntersectorSegment2Segment2 fifthClassify(FloatSegment2(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), FloatSegment2(lhsOrigin - lhsDirection, lhsOrigin - secondExtent * lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        FloatStaticTestIntersectorSegment2Segment2 sixthClassify(FloatSegment2(lhsOrigin, lhsOrigin + firstExtent * lhsDirection),
                                                                 FloatSegment2(rhsOrigin, rhsOrigin + secondExtent * rhsDirection));

        FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                true);

        if (0.0f <= seventhClassify.GetParameter0() && 0.0f <= seventhClassify.GetParameter1() &&
            seventhClassify.GetParameter0() <= firstExtent &&
            seventhClassify.GetParameter1() <= secondExtent)
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
