///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 20:36)

#include "StaticFindIntersectorRay2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorRay2Segment2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

namespace Mathematics
{
    template class StaticFindIntersectorRay2Segment2<float>;
    template class StaticFindIntersectorRay2Segment2<double>;
}

Mathematics::StaticFindIntersectorRay2Segment2Testing::StaticFindIntersectorRay2Segment2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersectorRay2Segment2Testing)

void Mathematics::StaticFindIntersectorRay2Segment2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersectorRay2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::StaticFindIntersectorRay2Segment2Testing::SegmentTest()
{
    std::default_random_engine generator;
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

        float extent = MathF::FAbs(randomDistribution(generator));

        if (extent < 1.0f)
        {
            extent = 1.5f;
        }

        StaticFindIntersectorRay2Segment2<float> firstClassify(Ray2F(lhsOrigin, lhsDirection), Segment2F(lhsOrigin, lhsOrigin + extent * lhsDirection, 1e-5f));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(firstClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin, firstClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + extent * lhsDirection, firstClassify.GetPoint(1), 1e-5f);

        StaticFindIntersectorRay2Segment2<float> secondClassify(Ray2F(lhsOrigin, lhsDirection), Segment2F(extent, rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticFindIntersectorRay2Segment2<float> thirdClassify(Ray2F(lhsOrigin, lhsDirection), Segment2F(extent, lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Segment);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin, thirdClassify.GetPoint(0), 1e-6f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + extent * lhsDirection, thirdClassify.GetPoint(1), 1e-6f);

        StaticFindIntersectorRay2Segment2<float> fifthClassify(Ray2F(lhsOrigin, lhsDirection), Segment2F(lhsOrigin - lhsDirection, lhsOrigin - lhsDirection - extent * lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

        StaticFindIntersectorRay2Segment2<float> sixthClassify(Ray2F(lhsOrigin, lhsDirection), Segment2F(extent, rhsOrigin, rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                  true);

        if (0.0f <= seventhClassify.GetParameter0() &&
            MathF::FAbs(seventhClassify.GetParameter1()) <= sixthClassify.GetSegment().GetExtent())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, lhsOrigin + seventhClassify.GetParameter0() * lhsDirection, sixthClassify.GetPoint(0), 1e-6f);
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
        }
    }
}
