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

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::SameTest()
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

        float thirdX = secondRandomDistribution(generator);
        distanceX = center.GetX() - thirdX;
        float thirdY = center.GetY() - FloatMath::Sqrt(radius * radius - distanceX * distanceX);

        float fourthX = secondRandomDistribution(generator);
        distanceX = center.GetX() - fourthX;
        float fourthY = center.GetY() - FloatMath::Sqrt(radius * radius - distanceX * distanceX);

        // 逆时针排序
        FloatArc2 testArc(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-5f);
        if (testArc.Contains(FloatVector2D(thirdX, thirdY)))
        {
            swap(thirdX, secondX);
            swap(thirdY, secondY);
        }

        testArc = FloatArc2(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-5f);
        if (testArc.Contains(FloatVector2D(fourthX, fourthY)))
        {
            swap(secondX, fourthX);
            swap(secondY, fourthY);
        }

        testArc = FloatArc2(center, radius, FloatVector2D(secondX, secondY), FloatVector2D(thirdX, thirdY), 1e-5f);
        if (testArc.Contains(FloatVector2D(fourthX, fourthY)))
        {
            swap(thirdX, fourthX);
            swap(thirdY, fourthY);
        }

        FloatArc2 firstArc(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 firstIntersector(firstArc, firstArc);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, firstIntersector.GetIntersectionType());
        ASSERT_TRUE(firstIntersector.IsIntersection());

        typedef bool (*ApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
                                            const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetRhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, firstIntersector.GetIntersectionArc(), firstArc, 1e-8f);
        ASSERT_EQUAL(firstIntersector.GetQuantity(), 0);

        FloatArc2 secondArc(center, radius, FloatVector2D(secondX, secondY), FloatVector2D(thirdX, thirdY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 secondIntersector(secondArc, firstArc);
        FloatStaticFindIntersectorArc2Arc2 thirdIntersector(firstArc, secondArc);

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
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(secondIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(secondIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-5f);
        }

        for (int i = 0; i < thirdIntersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(thirdIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(thirdIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-5f);
        }

        FloatArc2 thirdArc(center, radius, FloatVector2D(thirdX, thirdY), FloatVector2D(fourthX, fourthY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 fourthIntersector(thirdArc, firstArc);
        FloatStaticFindIntersectorArc2Arc2 fifthIntersector(firstArc, thirdArc);

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, fourthIntersector.GetIntersectionType());
        ASSERT_FALSE(fourthIntersector.IsIntersection());
        ASSERT_ENUM_EQUAL(IntersectionType::Empty, fifthIntersector.GetIntersectionType());
        ASSERT_FALSE(fifthIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fourthIntersector.GetLhsArc(), thirdArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fourthIntersector.GetRhsArc(), firstArc, 1e-8f);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fourthIntersector);
        ASSERT_EQUAL(fourthIntersector.GetQuantity(), 0);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fifthIntersector.GetLhsArc(), firstArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, fifthIntersector.GetRhsArc(), thirdArc, 1e-8f);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, fifthIntersector);
        ASSERT_EQUAL(fifthIntersector.GetQuantity(), 0);

        FloatArc2 fourthArc(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(thirdX, thirdY), 1e-5f);
        FloatArc2 fifthArc(center, radius, FloatVector2D(secondX, secondY), FloatVector2D(fourthX, fourthY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 sixthIntersector(fourthArc, fifthArc, 1e-5f);
        FloatStaticFindIntersectorArc2Arc2 seventhIntersector(fifthArc, fourthArc, 1e-5f);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, sixthIntersector.GetIntersectionType());
        ASSERT_TRUE(sixthIntersector.IsIntersection());
        ASSERT_ENUM_EQUAL(IntersectionType::Other, seventhIntersector.GetIntersectionType());
        ASSERT_TRUE(seventhIntersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetLhsArc(), fourthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetRhsArc(), fifthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, sixthIntersector.GetIntersectionArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(sixthIntersector.GetQuantity(), 0);

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetLhsArc(), fifthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetRhsArc(), fourthArc, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, seventhIntersector.GetIntersectionArc(), secondArc, 1e-8f);
        ASSERT_EQUAL(seventhIntersector.GetQuantity(), 0);

        FloatArc2 sixthArc(center, radius, FloatVector2D(firstX, firstY), FloatVector2D(fourthX, fourthY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 eighthIntersector(secondArc, sixthArc);
        FloatStaticFindIntersectorArc2Arc2 ninthIntersector(sixthArc, secondArc);

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

        maxX = rhsCenter.GetX() + rhsRadius;
        minX = rhsCenter.GetX() - rhsRadius;

        std::uniform_real<float> thirdRandomDistribution(minX, maxX);

        float thirdX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - thirdX;
        float thirdY = rhsCenter.GetY() - FloatMath::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        float fourthX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - fourthX;
        float fourthY = rhsCenter.GetY() - FloatMath::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        FloatArc2 secondArc(rhsCenter, rhsRadius, FloatVector2D(thirdX, thirdY), FloatVector2D(fourthX, fourthY), 1e-5f);

        FloatStaticFindIntersectorArc2Arc2 firstIntersector(firstArc, secondArc);

        typedef bool (*ApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
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

        maxX = rhsCenter.GetX() + rhsRadius;
        minX = rhsCenter.GetX() - rhsRadius;

        std::uniform_real<float> thirdRandomDistribution(minX, maxX);

        float thirdX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - thirdX;
        float thirdY = rhsCenter.GetY() - FloatMath::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        float fourthX = thirdRandomDistribution(generator);
        distanceX = rhsCenter.GetX() - fourthX;
        float fourthY = rhsCenter.GetY() - FloatMath::Sqrt(rhsRadius * rhsRadius - distanceX * distanceX);

        FloatArc2 firstArc(lhsCenter, lhsRadius, FloatVector2D(firstX, firstY), FloatVector2D(secondX, secondY), 1e-3f);
        FloatArc2 secondArc(rhsCenter, rhsRadius, FloatVector2D(thirdX, thirdY), FloatVector2D(fourthX, fourthY), 1e-4f);

        FloatStaticFindIntersectorArc2Arc2 firstIntersector(firstArc, secondArc);
        FloatStaticFindIntersectorCircle2Circle2 secondIntersector(lhsCircle2, rhsCircle2);

        typedef bool (*ApproximateFunction)(const FloatArc2& lhs, const FloatArc2& rhs,
                                            const float epsilon);

        ApproximateFunction approximate = Approximate<float>;

        vector<FloatVector2D> point;

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
                ASSERT_APPROXIMATE(FloatVector2DTools::Distance(firstIntersector.GetPoint(i), firstArc.GetCenter()), firstArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE(FloatVector2DTools::Distance(firstIntersector.GetPoint(i), secondArc.GetCenter()), secondArc.GetRadius(), 1e-4f);
                ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, firstIntersector.GetPoint(i), point[i], 1e-8f);
            }
        }
    }
}

void Mathematics::StaticFindIntersectorArc2Arc2Testing ::ExceptionTest(const StaticFindIntersectorArc2Arc2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetIntersectionArc();
}
