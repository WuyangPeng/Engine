///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 18:19)

#include "StaticFindIntersectorCircle2Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2Detail.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorCircle2Circle2Testing)

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TangentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::SameTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F center(randomDistribution(generator),
                              randomDistribution(generator));

        auto radius = MathF::FAbs(randomDistribution(generator));

        const Circle2F circle2(center, radius);

        StaticFindIntersectorCircle2Circle2<float> intersector(circle2, circle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), circle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), circle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetIntersectionCircle(), circle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 0);
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::EmptyTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto lhsRadius = MathF::FAbs(randomDistribution(generator));

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        // 第二个圆心在第一个圆上，必相交，修改半径值。
        if (MathF::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        const Circle2F lhsCircle2(lhsCenter, lhsRadius);

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

        const Circle2F rhsCircle2(rhsCenter, rhsRadius);

        StaticFindIntersectorCircle2Circle2<float> intersector(lhsCircle2, rhsCircle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, intersector.GetIntersectionType());
        ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::TangentTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto lhsRadius = MathF::FAbs(randomDistribution(generator));

        const Circle2F lhsCircle2(lhsCenter, lhsRadius);

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        const Circle2F rhsCircle2(rhsCenter, MathF::FAbs(distance - lhsRadius));

        StaticFindIntersectorCircle2Circle2<float> intersector(lhsCircle2, rhsCircle2, 1e-3f);

        ASSERT_ENUM_EQUAL(IntersectionType::Point, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 1);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);

        for (auto i = 0; i < intersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(intersector.GetPoint(i), lhsCircle2.GetCenter()), lhsCircle2.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(intersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-5f);
        }
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::PointTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto lhsRadius = MathF::FAbs(randomDistribution(generator));

        const Circle2F lhsCircle2(lhsCenter, lhsRadius);

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        auto distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        auto rhsRadius = MathF::FAbs(randomDistribution(generator));

        // 第二个圆心在第一个圆内
        if (distance < lhsRadius && distance < MathF::FAbs(lhsRadius - rhsRadius))
        {
            rhsRadius = lhsRadius - distance + 0.01f;
        }

        // 第二个圆心在第一个圆外
        if (lhsRadius < distance && rhsRadius + lhsRadius < distance)
        {
            rhsRadius = distance - lhsRadius + 0.01f;
        }

        if (lhsRadius < distance && distance + lhsRadius < rhsRadius)
        {
            rhsRadius = distance + lhsRadius - 0.01f;
        }

        const Circle2F rhsCircle2(rhsCenter, rhsRadius);

        StaticFindIntersectorCircle2Circle2<float> intersector(lhsCircle2, rhsCircle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Point, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_TRUE(0 < intersector.GetQuantity());

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);

        for (int i = 0; i < intersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(intersector.GetPoint(i), lhsCircle2.GetCenter()), lhsCircle2.GetRadius(), 1e-4f);
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(intersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-4f);
        }
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing::ExceptionTest(const StaticFindIntersectorCircle2Circle2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetIntersectionCircle();
}
