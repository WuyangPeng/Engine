// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:48)

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

void Mathematics::Intersector1Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::Intersector1Testing ::IntersectorTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float u0 = randomDistribution(generator);
        float u1 = randomDistribution(generator);
        float v0 = randomDistribution(generator);
        float v1 = randomDistribution(generator);

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
