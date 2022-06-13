///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 20:35)

#include "StaticFindIntersectorLine2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Segment2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Segment2Testing)

void Mathematics::StaticFindIntersectorLine2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing::SegmentTest()
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

        const float extent = MathF::FAbs(randomDistribution(generator));

        StaticFindIntersectorLine2Segment2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Segment2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondClassify);

        StaticFindIntersectorLine2Segment2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, thirdClassify);

        StaticFindIntersectorLine2Segment2<float> fourthClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, lhsOrigin + lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fourthClassify);

        StaticFindIntersectorLine2Segment2<float> fifthClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, lhsOrigin - lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fifthClassify);

        StaticFindIntersectorLine2Segment2<float> sixthClassify(Line2F(lhsOrigin, lhsDirection), Segment2F(extent, rhsOrigin, rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                  true);

        if (MathF::FAbs(seventhClassify.GetParameter1()) <= sixthClassify.GetSegment().GetExtent())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);

            Vector2F firstPoint = sixthClassify.GetPoint() - lhsOrigin;
            Vector2F secondPoint = sixthClassify.GetPoint() - rhsOrigin;

            firstPoint.Normalize();
            secondPoint.Normalize();

            ASSERT_TRUE(Vector2ToolsF::Approximate(firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f));

            ASSERT_TRUE(Vector2ToolsF::Approximate(secondPoint, sixthClassify.GetSegment().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-secondPoint, sixthClassify.GetSegment().GetDirection(), 1e-4f));
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
            ASSERT_THROW_EXCEPTION_1(ExceptionTest, sixthClassify);
        }
    }
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing::ExceptionTest(const StaticFindIntersectorLine2Segment2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetPoint();
}
