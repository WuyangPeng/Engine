// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:52)

#include "StaticFindIntersectorLine2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Segment2Detail.h"

#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include <random>

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Segment2Testing)

void Mathematics::StaticFindIntersectorLine2Segment2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing ::SegmentTest()
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

        FloatStaticFindIntersectorLine2Segment2 firstClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        FloatStaticFindIntersectorLine2Segment2 secondClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondClassify);

        FloatStaticFindIntersectorLine2Segment2 thirdClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, thirdClassify);

        FloatStaticFindIntersectorLine2Segment2 fourthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin + lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fourthClassify);

        FloatStaticFindIntersectorLine2Segment2 fifthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin - lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fifthClassify);

        FloatStaticFindIntersectorLine2Segment2 sixthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, rhsDirection));

        FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                true);

        if (FloatMath::FAbs(seventhClassify.GetParameter1()) <= sixthClassify.GetSegment().GetExtent())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);

            FloatVector2D firstPoint = sixthClassify.GetPoint() - lhsOrigin;
            FloatVector2D secondPoint = sixthClassify.GetPoint() - rhsOrigin;

            firstPoint.Normalize();
            secondPoint.Normalize();

            ASSERT_TRUE(FloatVector2DTools::Approximate(firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f) ||
                        FloatVector2DTools::Approximate(-firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f));

            ASSERT_TRUE(FloatVector2DTools::Approximate(secondPoint, sixthClassify.GetSegment().GetDirection(), 1e-4f) ||
                        FloatVector2DTools::Approximate(-secondPoint, sixthClassify.GetSegment().GetDirection(), 1e-4f));
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
            ASSERT_THROW_EXCEPTION_1(ExceptionTest, sixthClassify);
        }
    }
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing ::ExceptionTest(const StaticFindIntersectorLine2Segment2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetPoint();
}
