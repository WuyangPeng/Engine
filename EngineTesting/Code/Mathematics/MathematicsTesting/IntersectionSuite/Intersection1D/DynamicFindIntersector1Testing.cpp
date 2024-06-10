///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:51)

#include "DynamicFindIntersector1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/DynamicFindIntersector1Detail.h"
#include "Mathematics/Intersection/StaticTestIntersector1Detail.h"

#include <random>

Mathematics::DynamicFindIntersector1Testing::DynamicFindIntersector1Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DynamicFindIntersector1Testing)

void Mathematics::DynamicFindIntersector1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DynamicFindIntersector1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::DynamicFindIntersector1Testing::IntersectorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

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

        const auto tMax = MathD::FAbs(randomDistribution(generator));
        const auto speedU = randomDistribution(generator);
        const auto speedV = randomDistribution(generator);

        DynamicFindIntersector1<double> intersector1(u0, u1, v0, v1, tMax, speedU, speedV);

        ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-10);
        ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-10);
        ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-10);
        ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-10);

        ASSERT_EQUAL(0 < intersector1.GetNumIntersections(), intersector1.IsIntersection());

        if (u0 <= v1 && v0 <= u1)
        {
            ASSERT_TRUE(intersector1.IsIntersection());
            ASSERT_APPROXIMATE(intersector1.GetFirstTime(), 0.0f, 1e-10);

            for (int i = 0; i < intersector1.GetNumIntersections(); ++i)
            {
                ASSERT_TRUE(MathD::Approximate(u0, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(u1, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(v0, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(v1, intersector1.GetIntersection(i), 1e-10));

                ASSERT_TRUE(u0 <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= u1);
                ASSERT_TRUE(v0 <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= v1);
            }

            u0 += (intersector1.GetLastTime() * speedU);
            u1 += (intersector1.GetLastTime() * speedU);
            v0 += (intersector1.GetLastTime() * speedV);
            v1 += (intersector1.GetLastTime() * speedV);

            StaticTestIntersector1<double> staticIntersector1(u0, u1, v0, v1);
            ASSERT_TRUE(staticIntersector1.IsIntersection());

            u0 += (0.01 * speedU);
            u1 += (0.01 * speedU);
            v0 += (0.01 * speedV);
            v1 += (0.01 * speedV);

            StaticTestIntersector1<double> leaveStaticIntersector1(u0, u1, v0, v1);
            ASSERT_FALSE(leaveStaticIntersector1.IsIntersection());
        }
        else if (intersector1.IsIntersection())
        {
            auto lastU0 = u0 + intersector1.GetLastTime() * speedU;
            auto lastU1 = u1 + intersector1.GetLastTime() * speedU;
            auto lastV0 = v0 + intersector1.GetLastTime() * speedV;
            auto lastV1 = v1 + intersector1.GetLastTime() * speedV;

            StaticTestIntersector1<double> lastStaticIntersector1(lastU0, lastU1, lastV0, lastV1);

            ASSERT_TRUE(lastStaticIntersector1.IsIntersection());

            lastU0 += (0.01 * speedU);
            lastU1 += (0.01 * speedU);
            lastV0 += (0.01 * speedV);
            lastV1 += (0.01 * speedV);

            StaticTestIntersector1<double> leaveLastStaticIntersector1(lastU0, lastU1, lastV0, lastV1);
            ASSERT_FALSE(leaveLastStaticIntersector1.IsIntersection());

            auto firstU0 = u0 + intersector1.GetFirstTime() * speedU;
            auto firstU1 = u1 + intersector1.GetFirstTime() * speedU;
            auto firstV0 = v0 + intersector1.GetFirstTime() * speedV;
            auto firstV1 = v1 + intersector1.GetFirstTime() * speedV;

            StaticTestIntersector1<double> firstStaticIntersector1(firstU0, firstU1, firstV0, firstV1);

            ASSERT_TRUE(firstStaticIntersector1.IsIntersection());

            for (auto i = 0; i < intersector1.GetNumIntersections(); ++i)
            {
                ASSERT_TRUE(MathD::Approximate(firstU0, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(firstU1, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(firstV0, intersector1.GetIntersection(i), 1e-10) ||
                            MathD::Approximate(firstV1, intersector1.GetIntersection(i), 1e-10));

                ASSERT_TRUE(firstU0 - MathD::GetZeroTolerance() <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= firstU1 + MathD::GetZeroTolerance());
                ASSERT_TRUE(firstV0 - MathD::GetZeroTolerance() <= intersector1.GetIntersection(i) && intersector1.GetIntersection(i) <= firstV1 + MathD::GetZeroTolerance());
            }

            firstU0 -= (0.01 * speedU);
            firstU1 -= (0.01 * speedU);
            firstV0 -= (0.01 * speedV);
            firstV1 -= (0.01 * speedV);

            StaticTestIntersector1<double> leaveFirstStaticIntersector1(firstU0, firstU1, firstV0, firstV1);
            ASSERT_FALSE(leaveFirstStaticIntersector1.IsIntersection());
        }
        else
        {
            ASSERT_THROW_EXCEPTION_1(GetFirstTimeException, intersector1);
            ASSERT_THROW_EXCEPTION_1(GetLastTimeException, intersector1);

            ASSERT_EQUAL(0, intersector1.GetNumIntersections());
        }
    }
}

void Mathematics::DynamicFindIntersector1Testing::GetFirstTimeException(const DynamicFindIntersector1<double>& intersector1)
{
    MAYBE_UNUSED auto value = intersector1.GetFirstTime();
}

void Mathematics::DynamicFindIntersector1Testing::GetLastTimeException(const DynamicFindIntersector1<double>& intersector1)
{
    MAYBE_UNUSED auto value = intersector1.GetLastTime();
}
