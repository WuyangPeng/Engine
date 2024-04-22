///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:53)

#include "StaticFindIntersectorSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorSegment2Segment2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

#include <random>

namespace Mathematics
{
    template class StaticFindIntersectorSegment2Segment2<float>;
    template class StaticFindIntersectorSegment2Segment2<double>;
}

Mathematics::StaticFindIntersectorSegment2Segment2Testing::StaticFindIntersectorSegment2Segment2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersectorSegment2Segment2Testing)

void Mathematics::StaticFindIntersectorSegment2Segment2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersectorSegment2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorSegment2Segment2Testing::SegmentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution(-1.0f, 10.0f);

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

        float firstExtent = MathF::FAbs(randomDistribution(generator));
        float secondExtent = MathF::FAbs(randomDistribution(generator));

        if (firstExtent < 1.0f)
        {
            firstExtent = 1.1f;
        }

        if (secondExtent < 1.0f)
        {
            secondExtent = 1.1f;
        }

        StaticFindIntersectorSegment2Segment2<float> firstClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection));

        ASSERT_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin, firstClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + firstExtent * lhsDirection, firstClassify.GetPoint(1), 1e-6f);

        StaticFindIntersectorSegment2Segment2<float> secondClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(firstExtent, rhsOrigin, lhsDirection));

        ASSERT_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticFindIntersectorSegment2Segment2<float> thirdClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin, lhsOrigin - secondExtent * lhsDirection), 1e-5f);

        ASSERT_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin, thirdClassify.GetPoint(0), 1e-6f);

        StaticFindIntersectorSegment2Segment2<float> fourthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin + lhsDirection, lhsOrigin - secondExtent * lhsDirection), 1e-5f);

        ASSERT_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin, fourthClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + lhsDirection, fourthClassify.GetPoint(1), 1e-5f);

        StaticFindIntersectorSegment2Segment2<float> fifthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin - lhsDirection, lhsOrigin - secondExtent * lhsDirection));

        ASSERT_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        StaticFindIntersectorSegment2Segment2<float> sixthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection),
                                                                   Segment2F(rhsOrigin, rhsOrigin + secondExtent * rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, true);

        if (0.0f <= seventhClassify.GetParameter0() && 0.0f <= seventhClassify.GetParameter1() &&
            seventhClassify.GetParameter0() <= firstExtent &&
            seventhClassify.GetParameter1() <= secondExtent)
        {
            ASSERT_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + seventhClassify.GetParameter0() * lhsDirection, sixthClassify.GetPoint(0), 1e-5f);
        }
        else
        {
            ASSERT_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
        }
    }
}
