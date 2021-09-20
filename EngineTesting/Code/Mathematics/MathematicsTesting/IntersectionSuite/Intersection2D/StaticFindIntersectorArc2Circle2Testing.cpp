// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/30 18:50)

#include "StaticFindIntersectorArc2Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorArc2Circle2Detail.h"

#include <random>
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"
using std::swap;
using std::vector;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorArc2Circle2Testing)

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::SameTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D center(randomDistribution(generator),
                             randomDistribution(generator));

        float radius = FloatMath::FAbs(randomDistribution(generator));

        if (radius < 1.0f)
        {
            radius = 1.0f;
        }

        float maxX = center.GetX() + radius;
        float minX = center.GetX() - radius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = center.GetX() - firstX;
        float firstY = center.GetY() - FloatMath::Sqrt(radius * radius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = center.GetX() - secondX;
        float secondY = center.GetY() - FloatMath::Sqrt(radius * radius - distanceX * distanceX);

        FloatArc2 firstArc(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-5f);
        FloatCircle2 firstCircle(center, radius);

        FloatStaticFindIntersectorArc2Circle2 firstIntersector(firstArc, firstCircle);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, firstIntersector.GetIntersectionType());
        ASSERT_TRUE(firstIntersector.IsIntersection());

        typedef bool (*ArcApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const FloatCircle2& lhs, const FloatCircle2& rhs,
                                                  const float epsilon);

        CircleApproximateFunction circleApproximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(circleApproximate, firstIntersector.GetCircle(), firstCircle, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetIntersectionArc(), firstArc, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);
    }
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::EmptyTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D lhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float lhsRadius = FloatMath::FAbs(randomDistribution(generator));

        if (lhsRadius < 1.0f)
        {
            lhsRadius = 1.0f;
        }

        FloatVector2D rhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float distance = FloatVector2DTools::Distance(lhsCenter, rhsCenter);

        // 第二个圆心在第一个圆上，必相交，修改半径值。
        if (FloatMath::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        float maxX = lhsCenter.GetX() + lhsRadius;
        float minX = lhsCenter.GetX() - lhsRadius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = lhsCenter.GetX() - firstX;
        float firstY = lhsCenter.GetY() - FloatMath::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = lhsCenter.GetX() - secondX;
        float secondY = lhsCenter.GetY() - FloatMath::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        FloatArc2 firstArc(lhsCenter, lhsRadius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-4f);

        float rhsRadius = FloatMath::FAbs(randomDistribution(generator));

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

        FloatCircle2 firstCircle(rhsCenter, rhsRadius);

        FloatStaticFindIntersectorArc2Circle2 firstIntersector(firstArc, firstCircle);

        typedef bool (*ArcApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const FloatCircle2& lhs, const FloatCircle2& rhs,
                                                  const float epsilon);

        CircleApproximateFunction circleApproximate = Approximate<float>;

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
        ASSERT_FALSE(firstIntersector.IsIntersection());
        ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(circleApproximate, firstIntersector.GetCircle(), firstCircle, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
    }
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::PointTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D lhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float lhsRadius = FloatMath::FAbs(randomDistribution(generator));

        FloatCircle2 lhsCircle2(lhsCenter, lhsRadius);

        FloatVector2D rhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float distance = FloatVector2DTools::Distance(lhsCenter, rhsCenter);

        float rhsRadius = FloatMath::FAbs(randomDistribution(generator));

        // 第二个圆心在第一个圆内
        if (distance < lhsRadius && distance < FloatMath::FAbs(lhsRadius - rhsRadius))
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

        FloatCircle2 rhsCircle2(rhsCenter, rhsRadius);

        float maxX = lhsCenter.GetX() + lhsRadius;
        float minX = lhsCenter.GetX() - lhsRadius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = lhsCenter.GetX() - firstX;
        float firstY = lhsCenter.GetY() - FloatMath::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = lhsCenter.GetX() - secondX;
        float secondY = lhsCenter.GetY() - FloatMath::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        FloatArc2 firstArc(lhsCenter, lhsRadius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-3f);

        FloatStaticFindIntersectorArc2Circle2 firstIntersector(firstArc, rhsCircle2);
        FloatStaticFindIntersectorCircle2Circle2 secondIntersector(lhsCircle2, rhsCircle2);

        vector<FloatVector2D> point;

        for (int i = 0; i < secondIntersector.GetQuantity(); ++i)
        {
            if (firstArc.Contains(secondIntersector.GetPoint(i)))
            {
                point.push_back(secondIntersector.GetPoint(i));
            }
        }

        typedef bool (*ArcApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const FloatCircle2& lhs, const FloatCircle2& rhs,
                                                  const float epsilon);

        CircleApproximateFunction circleApproximate = Approximate<float>;

        if (point.empty())
        {
            ASSERT_ENUM_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
            ASSERT_FALSE(firstIntersector.IsIntersection());
            ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetArc(), firstArc, 1e-8f);
            ASSERT_APPROXIMATE_USE_FUNCTION(circleApproximate, firstIntersector.GetCircle(), rhsCircle2, 1e-8f);
            ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

            ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
        }
        else
        {
            ASSERT_ENUM_EQUAL(IntersectionType::Point, firstIntersector.GetIntersectionType());
            ASSERT_TRUE(firstIntersector.IsIntersection());

            ASSERT_APPROXIMATE_USE_FUNCTION(arcApproximate, firstIntersector.GetArc(), firstArc, 1e-8f);
            ASSERT_APPROXIMATE_USE_FUNCTION(circleApproximate, firstIntersector.GetCircle(), rhsCircle2, 1e-8f);
            ASSERT_TRUE(0 < firstIntersector.GetQuantity());

            ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);

            for (int i = 0; i < firstIntersector.GetQuantity(); ++i)
            {
                ASSERT_APPROXIMATE(FloatVector2DTools::Distance(firstIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE(FloatVector2DTools::Distance(firstIntersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, firstIntersector.GetPoint(i), point[i], 1e-8f);
            }
        }
    }
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::ExceptionTest(const StaticFindIntersectorArc2Circle2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetIntersectionArc();
}
