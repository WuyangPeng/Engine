// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/30 18:51)

#include "StaticFindIntersectorCircle2Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2Detail.h"

#include "Mathematics/Algebra/Vector2DTools.h"
#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorCircle2Circle2Testing)

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TangentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::SameTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D center(randomDistribution(generator),
                             randomDistribution(generator));

        float radius = FloatMath::FAbs(randomDistribution(generator));

        FloatCircle2 circle2(center, radius);

        FloatStaticFindIntersectorCircle2Circle2 intersector(circle2, circle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Other, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), circle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), circle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetIntersectionCircle(), circle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 0);
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::EmptyTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D lhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float lhsRadius = FloatMath::FAbs(randomDistribution(generator));

        FloatVector2D rhsCenter(randomDistribution(generator),
                                randomDistribution(generator));

        float distance = FloatVector2DTools::Distance(lhsCenter, rhsCenter);

        // �ڶ���Բ���ڵ�һ��Բ�ϣ����ཻ���޸İ뾶ֵ��
        if (FloatMath::Approximate(distance, lhsRadius, 1e-8f))
        {
            lhsRadius = distance / 2.0f;
        }

        FloatCircle2 lhsCircle2(lhsCenter, lhsRadius);

        float rhsRadius = FloatMath::FAbs(randomDistribution(generator));

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

        FloatCircle2 rhsCircle2(rhsCenter, rhsRadius);

        FloatStaticFindIntersectorCircle2Circle2 intersector(lhsCircle2, rhsCircle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Empty, intersector.GetIntersectionType());
        ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 0);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::TangentTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

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

        FloatCircle2 rhsCircle2(rhsCenter, FloatMath::FAbs(distance - lhsRadius));

        FloatStaticFindIntersectorCircle2Circle2 intersector(lhsCircle2, rhsCircle2, 1e-3f);

        ASSERT_ENUM_EQUAL(IntersectionType::Point, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_EQUAL(intersector.GetQuantity(), 1);

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);

        for (int i = 0; i < intersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(intersector.GetPoint(i), lhsCircle2.GetCenter()), lhsCircle2.GetRadius(), 1e-5f);
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(intersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-5f);
        }
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::PointTest()
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

        // �ڶ���Բ���ڵ�һ��Բ��
        if (distance < lhsRadius && distance < FloatMath::FAbs(lhsRadius - rhsRadius))
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

        FloatCircle2 rhsCircle2(rhsCenter, rhsRadius);

        FloatStaticFindIntersectorCircle2Circle2 intersector(lhsCircle2, rhsCircle2);

        ASSERT_ENUM_EQUAL(IntersectionType::Point, intersector.GetIntersectionType());
        ASSERT_TRUE(intersector.IsIntersection());

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetLhsCircle(), lhsCircle2, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, intersector.GetRhsCircle(), rhsCircle2, 1e-8f);
        ASSERT_TRUE(0 < intersector.GetQuantity());

        ASSERT_THROW_EXCEPTION_1(ExceptionTest, intersector);

        for (int i = 0; i < intersector.GetQuantity(); ++i)
        {
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(intersector.GetPoint(i), lhsCircle2.GetCenter()), lhsCircle2.GetRadius(), 1e-4f);
            ASSERT_APPROXIMATE(FloatVector2DTools::Distance(intersector.GetPoint(i), rhsCircle2.GetCenter()), rhsCircle2.GetRadius(), 1e-4f);
        }
    }
}

void Mathematics::StaticFindIntersectorCircle2Circle2Testing ::ExceptionTest(const StaticFindIntersectorCircle2Circle2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetIntersectionCircle();
}
