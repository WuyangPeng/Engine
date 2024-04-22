///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:52)

#include "StaticFindIntersectorArc2Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorArc2Circle2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

#include <random>

Mathematics::StaticFindIntersectorArc2Circle2Testing::StaticFindIntersectorArc2Circle2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersectorArc2Circle2Testing)

void Mathematics::StaticFindIntersectorArc2Circle2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing::SameTest() noexcept
{
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing::EmptyTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        float lhsRadius = MathF::FAbs(randomDistribution(generator));

        if (lhsRadius < 1.0f)
        {
            lhsRadius = 1.0f;
        }

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        const float distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        // 第二个圆心在第一个圆上，必相交，修改半径值。
        if (MathF::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        const float maxX = lhsCenter.GetX() + lhsRadius;
        const float minX = lhsCenter.GetX() - lhsRadius;

        std::uniform_real<float> randomDistribution1(minX, maxX);

        const float firstX = randomDistribution1(generator);
        float distanceX = lhsCenter.GetX() - firstX;
        const float firstY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        const float secondX = randomDistribution1(generator);
        distanceX = lhsCenter.GetX() - secondX;
        const float secondY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        const Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-3f);

        float rhsRadius = MathF::FAbs(randomDistribution(generator));

        // 第二个圆心在第一个圆内
        if (distance < lhsRadius && lhsRadius - rhsRadius <= distance)
        {
            rhsRadius = lhsRadius - distance - 0.01f;
        }

        // 第二个圆心在第一个圆外
        if (lhsRadius < distance && distance - lhsRadius <= rhsRadius)
        {
            rhsRadius = distance - lhsRadius - 0.01f;
        }

        const Circle2F firstCircle(rhsCenter, rhsRadius);

        StaticFindIntersectorArc2Circle2<float> firstIntersector(firstArc, firstCircle);

        using ArcApproximateFunction = bool (*)(const Arc2F& lhs, const Arc2F& rhs, const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        using CircleApproximateFunction = bool (*)(const Circle2F& lhs, const Circle2F& rhs, const float epsilon);

        CircleApproximateFunction circleApproximate = Approximate<float>;

        ASSERT_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
        ASSERT_FALSE(firstIntersector.IsIntersection());
        ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(circleApproximate, firstIntersector.GetCircle(), firstCircle, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
    }
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing::PointTest() noexcept
{
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing::ExceptionTest(const StaticFindIntersectorArc2Circle2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetIntersectionArc();
}
