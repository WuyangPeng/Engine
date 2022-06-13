///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 18:36)

#include "StaticFindIntersectorLine2Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Line2Detail.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Line2Testing)

void Mathematics::StaticFindIntersectorLine2Line2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::StaticFindIntersectorLine2Line2Testing::LineTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

        StaticFindIntersectorLine2Line2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Line2F(lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Line2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondClassify);

        StaticFindIntersectorLine2Line2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, rhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        Vector2F firstPoint = thirdClassify.GetPoint() - thirdClassify.GetLhsLine().GetOrigin();
        Vector2F secondPoint = thirdClassify.GetPoint() - thirdClassify.GetRhsLine().GetOrigin();

        firstPoint.Normalize();
        secondPoint.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(firstPoint, thirdClassify.GetLhsLine().GetDirection(), 1e-4f) ||
                    Vector2ToolsF::Approximate(-firstPoint, thirdClassify.GetLhsLine().GetDirection(), 1e-4f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(secondPoint, thirdClassify.GetRhsLine().GetDirection(), 1e-4f) ||
                    Vector2ToolsF::Approximate(-secondPoint, thirdClassify.GetRhsLine().GetDirection(), 1e-4f));
    }
}

void Mathematics::StaticFindIntersectorLine2Line2Testing::ExceptionTest(const StaticFindIntersectorLine2Line2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetPoint();
}
