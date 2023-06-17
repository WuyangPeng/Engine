///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:52)

#include "StaticFindIntersector1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticFindIntersector1<float>;
    template class StaticFindIntersector1<double>;
}

Mathematics::StaticFindIntersector1Testing::StaticFindIntersector1Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersector1Testing)

void Mathematics::StaticFindIntersector1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersector1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::StaticFindIntersector1Testing::IntersectorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto u0 = randomDistribution(generator);
        auto u1 = randomDistribution(generator);
        auto v0 = randomDistribution(generator);
        auto v1 = randomDistribution(generator);

        if (u1 < u0)
        {
            std::swap(u0, u1);
        }

        if (v1 < v0)
        {
            std::swap(v0, v1);
        }

        StaticFindIntersector1<float> intersector1(u0, u1, v0, v1);

        ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-8f);
        ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-8f);
        ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-8f);
        ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-8f);

        ASSERT_EQUAL(u0 <= v1 && v0 <= u1, intersector1.IsIntersection());
        ASSERT_EQUAL(0 < intersector1.GetNumIntersections(), intersector1.IsIntersection());

        for (auto i = 0; i < intersector1.GetNumIntersections(); ++i)
        {
            ASSERT_TRUE(MathF::Approximate(u0, intersector1.GetIntersection(i), 1e-8f) ||
                        MathF::Approximate(u1, intersector1.GetIntersection(i), 1e-8f) ||
                        MathF::Approximate(v0, intersector1.GetIntersection(i), 1e-8f) ||
                        MathF::Approximate(v1, intersector1.GetIntersection(i), 1e-8f));

            ASSERT_TRUE(u0 <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= u1);
            ASSERT_TRUE(v0 <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= v1);
        }
    }
}
