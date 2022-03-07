// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/30 18:50)

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
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::StaticFindIntersectorArc2Arc2Testing ::MainTest()
{
    // ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    // ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::SameTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

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

        float thirdX = secondRandomDistribution(generator);
        distanceX = center.GetX() - thirdX;
        float thirdY = center.GetY() - MathF::Sqrt(radius * radius - distanceX * distanceX);

        float fourthX = secondRandomDistribution(generator);
        distanceX = center.GetX() - fourthX;
        float fourthY = center.GetY() - MathF::Sqrt(radius * radius - distanceX * distanceX);

        // 逆时针排序
        Arc2F testArc(center, radius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-4f);
        if (testArc.Contains(Vector2F(thirdX, thirdY)))
        {
            swap(thirdX, secondX);
            swap(thirdY, secondY);
        }

        testArc = Arc2F(center, radius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-4f);
        if (testArc.Contains(Vector2F(fourthX, fourthY)))
        {
            swap(secondX, fourthX);
            swap(secondY, fourthY);
        }

        testArc = Arc2F(center, radius, Vector2F(secondX, secondY), Vector2F(thirdX, thirdY), 1e-4f);
        if (testArc.Contains(Vector2F(fourthX, fourthY)))
        {
            swap(thirdX, fourthX);
            swap(thirdY, fourthY);
        }

        Arc2F firstArc(center, radius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> firstIntersector(firstArc, firstArc);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, firstIntersector.GetIntersectionType());
        ASSERT_TRUE(firstIntersector.IsIntersection());

        typedef bool (*ApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                            const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetIntersectionArc(), firstArc, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        Arc2F secondArc(center, radius, Vector2F(secondX, secondY), Vector2F(thirdX, thirdY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> secondIntersector(secondArc, firstArc);
        StaticFindIntersectorArc2Arc2<float> thirdIntersector(firstArc, secondArc);

        ASSERT_ENUM_EQUAL(IntersectionType::Point, secondIntersector.GetIntersectionType());
        ASSERT_TRUE(secondIntersector.IsIntersection());
        ASSERT_ENUM_EQUAL(IntersectionType::Point, thirdIntersector.GetIntersectionType());
        ASSERT_TRUE(thirdIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, secondIntersector.GetLhsArc(), secondArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, secondIntersector.GetRhsArc(), firstArc, 1e-8f);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondIntersector);
        ASSERT_EQUAL(secondIntersector.GetQuantity(), 1);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, thirdIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, thirdIntersector.GetRhsArc(), secondArc, 1e-8f);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, thirdIntersector);
        ASSERT_EQUAL(thirdIntersector.GetQuantity(), 1);

        for (int i = 0; i < secondIntersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(secondIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(secondIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-5f);
        }

        for (int i = 0; i < thirdIntersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(thirdIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(Vector2ToolsF::Distance(thirdIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-5f);
        }

        Arc2F thirdArc(center, radius, Vector2F(thirdX, thirdY), Vector2F(fourthX, fourthY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> fourthIntersector(thirdArc, firstArc);
        StaticFindIntersectorArc2Arc2<float> fifthIntersector(firstArc, thirdArc);

        //  ASSERT_ENUM_EQUAL(IntersectionType::Empty, fourthIntersector.GetIntersectionType());
        //ASSERT_FALSE(fourthIntersector.IsIntersection());
        //  ASSERT_ENUM_EQUAL(IntersectionType::Empty, fifthIntersector.GetIntersectionType());
        //ASSERT_FALSE(fifthIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fourthIntersector.GetLhsArc(), thirdArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fourthIntersector.GetRhsArc(), firstArc, 1e-8f);
        //  ASSERT_THROW_EXCEPTION_1(ExceptionTest, fourthIntersector);
        ASSERT_EQUAL(fourthIntersector.GetQuantity(), 0);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fifthIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fifthIntersector.GetRhsArc(), thirdArc, 1e-8f);
        //  ASSERT_THROW_EXCEPTION_1(ExceptionTest, fifthIntersector);
        ASSERT_EQUAL(fifthIntersector.GetQuantity(), 0);

        Arc2F fourthArc(center, radius, Vector2F(firstX, firstY), Vector2F(thirdX, thirdY), 1e-4f);
        Arc2F fifthArc(center, radius, Vector2F(secondX, secondY), Vector2F(fourthX, fourthY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> sixthIntersector(fourthArc, fifthArc, 1e-4f);
        StaticFindIntersectorArc2Arc2<float> seventhIntersector(fifthArc, fourthArc, 1e-4f);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, sixthIntersector.GetIntersectionType());
        ASSERT_TRUE(sixthIntersector.IsIntersection());
        ASSERT_ENUM_EQUAL(IntersectionType::Other, seventhIntersector.GetIntersectionType());
        ASSERT_TRUE(seventhIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetLhsArc(), fourthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetRhsArc(), fifthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetIntersectionArc(), secondArc, 1e-4f);
        ASSERT_EQUAL(sixthIntersector.GetQuantity(), 0);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetLhsArc(), fifthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetRhsArc(), fourthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetIntersectionArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(seventhIntersector.GetQuantity(), 0);

        Arc2F sixthArc(center, radius, Vector2F(firstX, firstY), Vector2F(fourthX, fourthY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> eighthIntersector(secondArc, sixthArc);
        StaticFindIntersectorArc2Arc2<float> ninthIntersector(sixthArc, secondArc);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, eighthIntersector.GetIntersectionType());
        ASSERT_TRUE(eighthIntersector.IsIntersection());
        ASSERT_ENUM_EQUAL(IntersectionType::Other, ninthIntersector.GetIntersectionType());
        ASSERT_TRUE(ninthIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, ninthIntersector.GetLhsArc(), sixthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, ninthIntersector.GetRhsArc(), secondArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, ninthIntersector.GetIntersectionArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(ninthIntersector.GetQuantity(), 0);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, eighthIntersector.GetLhsArc(), secondArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, eighthIntersector.GetRhsArc(), sixthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, eighthIntersector.GetIntersectionArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(eighthIntersector.GetQuantity(), 0);
    }
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::EmptyTest()
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

        // 第二个圆心在第一个圆上，必相交，修改半径值。
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

        Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-4f);

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

        if (rhsRadius < 0.0f)
        {
            rhsRadius = 0.0f;
        }

        maxX = rhsCenter.GetX() + rhsRadius;
        minX = rhsCenter.GetX() - rhsRadius;

        std::uniform_real<float> thirdRandomDistribution(minX, maxX);

        float thirdX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - thirdX;
        float thirdY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        float fourthX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - fourthX;
        float fourthY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        Arc2F secondArc(rhsCenter, rhsRadius, Vector2F(thirdX, thirdY), Vector2F(fourthX, fourthY), 1e-5f);

        StaticFindIntersectorArc2Arc2<float> firstIntersector(firstArc, secondArc, 1e-2f);

        typedef bool (*ApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                            const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
        ASSERT_FALSE(firstIntersector.IsIntersection());
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
    }
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::PointTest()
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

        maxX = rhsCenter.GetX() + rhsRadius;
        minX = rhsCenter.GetX() - rhsRadius;

        std::uniform_real<float> thirdRandomDistribution(minX, maxX);

        float thirdX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - thirdX;
        float thirdY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        float fourthX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - fourthX;
        float fourthY = rhsCenter.GetY() - MathF::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        Arc2F firstArc(lhsCenter, lhsRadius, Vector2F(firstX, firstY), Vector2F(secondX, secondY), 1e-3f);
        Arc2F secondArc(rhsCenter, rhsRadius, Vector2F(thirdX, thirdY), Vector2F(fourthX, fourthY), 1e-4f);

        StaticFindIntersectorArc2Arc2<float> firstIntersector(firstArc, secondArc, 1e-4f);
        StaticFindIntersectorCircle2Circle2<float> secondIntersector(lhsCircle2, rhsCircle2, 1e-4f);

        typedef bool (*ApproximateFunction)(const Arc2F& lhs, const Arc2F& rhs,
                                            const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        vector<Vector2F> point;

        for (int i = 0; i < secondIntersector.GetQuantity(); ++i)
        {
            if (firstArc.Contains(secondIntersector.GetPoint(i)) &&
                secondArc.Contains(secondIntersector.GetPoint(i)))
            {
                point.push_back(secondIntersector.GetPoint(i));
            }
        }

        if (point.empty())
        {
            ASSERT_ENUM_EQUAL(IntersectionType::Empty, firstIntersector.GetIntersectionType());
            ASSERT_FALSE(firstIntersector.IsIntersection());
            ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
            ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), secondArc, 1e-8f);
            ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

            ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);
        }
        else
        {
            ASSERT_ENUM_EQUAL(IntersectionType::Point, firstIntersector.GetIntersectionType());
            ASSERT_TRUE(firstIntersector.IsIntersection());

            ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
            ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), secondArc, 1e-8f);
            ASSERT_TRUE(0 < firstIntersector.GetQuantity());

            ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstIntersector);

            for (int i = 0; i < firstIntersector.GetQuantity(); ++i)
            {
                ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, firstIntersector.GetPoint(i), point.at(i), 1e-8f);
            }
        }
    }
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::ExceptionTest(const StaticFindIntersectorArc2Arc2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetIntersectionArc();
}
