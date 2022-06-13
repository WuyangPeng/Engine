///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 11:25)

#include "StaticTestIntersector1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticTestIntersector1Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
    template class StaticTestIntersector1<float>;
    template class StaticTestIntersector1<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersector1Testing)

void Mathematics::StaticTestIntersector1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::StaticTestIntersector1Testing::IntersectorTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto u0 = randomDistribution(generator);
        auto u1 = randomDistribution(generator);
        auto v0 = randomDistribution(generator);
        auto v1 = randomDistribution(generator);

        if (u1 < u0)
        {
            swap(u0, u1);
        }

        if (v1 < v0)
        {
            swap(v0, v1);
        }

        StaticTestIntersector1<float> intersector1(u0, u1, v0, v1);

        ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-8f);
        ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-8f);
        ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-8f);
        ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-8f);

        ASSERT_EQUAL(u0 <= v1 && v0 <= u1, intersector1.IsIntersection());
    }
}
