///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:53)

#include "StaticFindIntersectorLine2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Segment2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

#include <random>

Mathematics::StaticFindIntersectorLine2Segment2Testing::StaticFindIntersectorLine2Segment2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersectorLine2Segment2Testing)

void Mathematics::StaticFindIntersectorLine2Segment2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorLine2Segment2Testing::SegmentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

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

            Vector2F point0 = sixthClassify.GetPoint() - lhsOrigin;
            Vector2F point1 = sixthClassify.GetPoint() - rhsOrigin;

            point0.Normalize();
            point1.Normalize();

            ASSERT_TRUE(Vector2ToolsF::Approximate(point0, sixthClassify.GetLine().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-point0, sixthClassify.GetLine().GetDirection(), 1e-4f));

            ASSERT_TRUE(Vector2ToolsF::Approximate(point1, sixthClassify.GetSegment().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-point1, sixthClassify.GetSegment().GetDirection(), 1e-4f));
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
