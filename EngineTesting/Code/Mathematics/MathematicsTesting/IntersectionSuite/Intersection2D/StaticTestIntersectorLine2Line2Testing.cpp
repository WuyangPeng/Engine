///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 20:37)

#include "StaticTestIntersectorLine2Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Line2Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorLine2Line2<float>;
    template class StaticTestIntersectorLine2Line2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorLine2Line2Testing)

void Mathematics::StaticTestIntersectorLine2Line2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::StaticTestIntersectorLine2Line2Testing::LineTest()
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

        StaticTestIntersectorLine2Line2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Line2F(lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);

        StaticTestIntersectorLine2Line2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

        StaticTestIntersectorLine2Line2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, rhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);
    }
}
