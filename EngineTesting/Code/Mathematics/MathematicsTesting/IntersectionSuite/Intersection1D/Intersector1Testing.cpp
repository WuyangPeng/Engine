///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:51)

#include "Intersector1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/Intersector1TestDetail.h"

#include <random>

namespace Mathematics
{
    template class Intersector1Test<float>;
    template class Intersector1Test<double>;
}

Mathematics::Intersector1Testing::Intersector1Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Intersector1Testing)

void Mathematics::Intersector1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Intersector1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::Intersector1Testing::IntersectorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-100.0f, 100.0f);

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

        Intersector1Test<float> intersector1(u0, u1, v0, v1);

        ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-8f);
        ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-8f);
        ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-8f);
        ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-8f);
    }
}
