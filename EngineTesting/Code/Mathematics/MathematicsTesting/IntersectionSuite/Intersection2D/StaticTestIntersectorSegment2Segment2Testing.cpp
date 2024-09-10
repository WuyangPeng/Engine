///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:54)

#include "StaticTestIntersectorSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorSegment2Segment2Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticTestIntersector<Segment2F, Segment2F>;
    template class StaticTestIntersector<Segment2D, Segment2D>;
}

Mathematics::StaticTestIntersectorSegment2Segment2Testing::StaticTestIntersectorSegment2Segment2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticTestIntersectorSegment2Segment2Testing)

void Mathematics::StaticTestIntersectorSegment2Segment2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticTestIntersectorSegment2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticTestIntersectorSegment2Segment2Testing::SegmentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-1.0f, 1.0f);

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

        const float firstExtent = MathF::FAbs(randomDistribution(generator));
        const float secondExtent = MathF::FAbs(randomDistribution(generator));

        StaticTestIntersector firstClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(firstExtent, lhsOrigin, lhsDirection));

        ASSERT_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);

        StaticTestIntersector secondClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(firstExtent, rhsOrigin, lhsDirection));

        ASSERT_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticTestIntersector<Segment2F, Segment2F> thirdClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin, lhsOrigin - secondExtent * lhsDirection), 1e-4f);

        ASSERT_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        StaticTestIntersector fourthClassify(Segment2F(firstExtent, lhsOrigin, lhsDirection), Segment2F(secondExtent, lhsOrigin, -lhsDirection));

        ASSERT_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);

        StaticTestIntersector fifthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection), Segment2F(lhsOrigin - lhsDirection, lhsOrigin - secondExtent * lhsDirection));

        ASSERT_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        StaticTestIntersector sixthClassify(Segment2F(lhsOrigin, lhsOrigin + firstExtent * lhsDirection),
                                            Segment2F(rhsOrigin, rhsOrigin + secondExtent * rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, true);

        if (0.0f <= seventhClassify.GetParameter0() && 0.0f <= seventhClassify.GetParameter1() &&
            seventhClassify.GetParameter0() <= firstExtent &&
            seventhClassify.GetParameter1() <= secondExtent)
        {
            ASSERT_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
        }
        else
        {
            ASSERT_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
        }
    }
}
