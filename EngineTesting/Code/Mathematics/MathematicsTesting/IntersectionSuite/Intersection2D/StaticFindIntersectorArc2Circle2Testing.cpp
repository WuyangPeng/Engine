// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/30 18:50)

#include "StaticFindIntersectorArc2Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorArc2Circle2Detail.h"

#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"
#include <random>
using std::swap;
using std::vector;
#include SYSTEM_WARNING_DISABLE(26496)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorArc2Circle2Testing)

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::MainTest()
{
    //ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    // ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::SameTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F center(randomDistribution(generator),
                        randomDistribution(generator));

        float radius = MathF::FAbs(randomDistribution(generator));

        if (radius < 1.0f)
        {
            radius = 1.0f;
        }

        float maxX = center.GetX() + radius;
        float minX = center.GetX() - radius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = center.GetX() - firstX;
        float firstY = center.GetY() - MathF::Sqrt(radius * radius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = center.GetX() - secondX;
        float secondY = center.GetY() - MathF::Sqrt(radius * radius - distanceX * distanceX);

        Arc2F firstArc(center, radius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-5f);
        Circle2F firstCircle(center, radius);

        StaticFindIntersectorArc2Circle2<float> firstIntersector(firstArc, firstCircle);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, firstIntersector.GetIntersectionType());
        ASSERT_TRUE(firstIntersector.IsIntersection());

        typedef bool (*ArcApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const Circle2F& lhs, const Circle2F& rhs,
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
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F lhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        float lhsRadius = MathF::FAbs(randomDistribution(generator));

        if (lhsRadius < 1.0f)
        {
            lhsRadius = 1.0f;
        }

        Vector2F rhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        float distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        // �ڶ���Բ���ڵ�һ��Բ�ϣ����ཻ���޸İ뾶ֵ��
        if (MathF::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        float maxX = lhsCenter.GetX() + lhsRadius;
        float minX = lhsCenter.GetX() - lhsRadius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = lhsCenter.GetX() - firstX;
        float firstY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = lhsCenter.GetX() - secondX;
        float secondY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-3f);

        float rhsRadius = MathF::FAbs(randomDistribution(generator));

        // �ڶ���Բ���ڵ�һ��Բ��
        if (distance < lhsRadius && lhsRadius - rhsRadius <= distance)
        {
            rhsRadius = lhsRadius - distance - 0.01f;
        }

        // �ڶ���Բ���ڵ�һ��Բ��
        if (lhsRadius < distance && distance - lhsRadius <= rhsRadius)
        {
            rhsRadius = distance - lhsRadius - 0.01f;
        }

        Circle2F firstCircle(rhsCenter, rhsRadius);

        StaticFindIntersectorArc2Circle2<float> firstIntersector(firstArc, firstCircle);

        typedef bool (*ArcApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const Circle2F& lhs, const Circle2F& rhs,
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
        Vector2F lhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        float lhsRadius = MathF::FAbs(randomDistribution(generator));

        Circle2F lhsCircle2(lhsCenter, lhsRadius);

        Vector2F rhsCenter(randomDistribution(generator),
                           randomDistribution(generator));

        float distance = Vector2ToolsF::Distance(lhsCenter, rhsCenter);

        float rhsRadius = MathF::FAbs(randomDistribution(generator));

        // �ڶ���Բ���ڵ�һ��Բ��
        if (distance < lhsRadius && distance < MathF::FAbs(lhsRadius - rhsRadius))
        {
            rhsRadius = lhsRadius - distance + 0.01f;
        }

        // �ڶ���Բ���ڵ�һ��Բ��
        if (lhsRadius < distance && rhsRadius + lhsRadius < distance)
        {
            rhsRadius = distance - lhsRadius + 0.01f;
        }

        if (lhsRadius < distance && distance + lhsRadius < rhsRadius)
        {
            rhsRadius = distance + lhsRadius - 0.01f;
        }

        Circle2F rhsCircle2(rhsCenter, rhsRadius);

        float maxX = lhsCenter.GetX() + lhsRadius;
        float minX = lhsCenter.GetX() - lhsRadius;

        std::uniform_real<float> secondRandomDistribution(minX, maxX);

        float firstX = secondRandomDistribution(generator);
        float distanceX = lhsCenter.GetX() - firstX;
        float firstY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        float secondX = secondRandomDistribution(generator);
        distanceX = lhsCenter.GetX() - secondX;
        float secondY = lhsCenter.GetY() - MathF::Sqrt(lhsRadius * lhsRadius - distanceX * distanceX);

        Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-3f);

        StaticFindIntersectorArc2Circle2<float> firstIntersector(firstArc, rhsCircle2);
        StaticFindIntersectorCircle2Circle2<float> secondIntersector(lhsCircle2, rhsCircle2);

        vector<Vector2F> point;

        for (int i = 0; i < secondIntersector.GetQuantity(); ++i)
        {
            if (firstArc.Contains(secondIntersector.GetPoint(i)))
            {
                point.push_back(secondIntersector.GetPoint(i));
            }
        }

        typedef bool (*ArcApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                               const float epsilon);

        ArcApproximateFunction arcApproximate = Approximate<float>;

        typedef bool (*CircleApproximateFunction)(const Circle2F& lhs, const Circle2F& rhs,
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
                ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstIntersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, firstIntersector.GetPoint(i), point.at(i), 1e-8f);
            }
        }
    }
}

void Mathematics::StaticFindIntersectorArc2Circle2Testing ::ExceptionTest(const StaticFindIntersectorArc2Circle2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetIntersectionArc();
}