///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 21:06)

#include "StaticTestIntersectorSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorSegment2Segment2Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorSegment2Segment2<float>;
    template class StaticTestIntersectorSegment2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorSegment2Segment2Testing)

void Mathematics::StaticTestIntersectorSegment2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticTestIntersectorSegment2Segment2Testing::SegmentTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

        const float firstExtent = MathF::FAbs(randomDistribution(generator));
        const float secondExtent = MathF::FAbs(randomDistribution(generator));

        StaticTestIntersectorSegment2Segment2<float> firstClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(firstExtent, lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);

        StaticTestIntersectorSegment2Segment2<float> secondClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(firstExtent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticTestIntersectorSegment2Segment2<float> thirdClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin, lhsOrigin - secondExtent * lhsDirection), 1e-5f);

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        StaticTestIntersectorSegment2Segment2<float> fourthClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(secondExtent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);

        StaticTestIntersectorSegment2Segment2<float> fifthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin - lhsDirection, lhsOrigin - secondExtent * lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        StaticTestIntersectorSegment2Segment2<float> sixthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection),
                                                                   Segment2F(rhsOrigin, rhsOrigin + secondExtent * rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, true);

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
