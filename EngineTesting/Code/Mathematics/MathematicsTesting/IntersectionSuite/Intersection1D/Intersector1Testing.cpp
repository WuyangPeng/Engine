///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 11:25)

#include "Intersector1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/Intersector1TestDetail.h"

#include <random>

using std::swap;

namespace Mathematics
{
    template class Intersector1Test<float>;
    template class Intersector1Test<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Intersector1Testing)

void Mathematics::Intersector1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::Intersector1Testing::IntersectorTest()
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

        Intersector1Test<float> intersector1(u0, u1, v0, v1);

        ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-8f);
        ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-8f);
        ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-8f);
        ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-8f);
    }
}
