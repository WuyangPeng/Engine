///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 11:28)

#include "StaticFindIntersectorArc2Arc2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorArc2Arc2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

#include <random>

using std::swap;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorArc2Arc2Testing)

void Mathematics::StaticFindIntersectorArc2Arc2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing::SameTest() noexcept
{
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing::EmptyTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto lhsRadius = MathF::FAbs(randomDistribution(generator));

        if (lhsRadius < 1.0f)
        {
            lhsRadius = 1.0f;
        }

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        const auto distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        // 第二个圆心在第一个圆上，必相交，修改半径值。
        if (MathF::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        auto maxX = lhsCenter.GetX() + lhsRadius;
        auto minX = lhsCenter.GetX() - lhsRadius;

        const std::uniform_real<float> secondRandomDistribution(minX, maxX);

        const auto firstX = secondRandomDistribution(generator);
        auto distanceX = lhsCenter.GetX() - firstX;
        const auto firstY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        const auto secondX = secondRandomDistribution(generator);
        distanceX = lhsCenter.GetX() - secondX;
        const auto secondY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        const Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-4f);

        auto rhsRadius = MathF::FAbs(randomDistribution(generator));

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

        if (rhsRadius < 0.0f)
        {
            rhsRadius = 0.0f;
        }

        maxX = rhsCenter.GetX() + rhsRadius;
        minX = rhsCenter.GetX() - rhsRadius;

        const std::uniform_real<float> thirdRandomDistribution(minX, maxX);

        const auto thirdX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - thirdX;
        const auto thirdY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        const auto fourthX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - fourthX;
        const auto fourthY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        const Arc2F secondArc(rhsCenter, rhsRadius, Vector2F(thirdX, thirdY), Vector2F(fourthX, fourthY), 1e-5f);

        StaticFindIntersectorArc2Arc2<float> firstIntersector(firstArc, secondArc, 1e-2f);

        using ApproximateFunction = bool (*)(const Arc2F& lhs, const Arc2F& rhs, const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
        ASSERT_FALSE(firstIntersector.IsIntersection());
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
    }
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing::PointTest() noexcept
{
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing::ExceptionTest(const StaticFindIntersectorArc2Arc2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetIntersectionArc();
}
