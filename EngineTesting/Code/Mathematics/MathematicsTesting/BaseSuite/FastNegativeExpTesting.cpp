// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:59)

#include "FastNegativeExpTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/FastNegativeExpDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class FastNegativeExp<float>;
    template class FastNegativeExp<double>;
}
#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, FastNegativeExpTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::FastNegativeExpTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpBoundaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpBoundaryTest);
}

void Mathematics::FastNegativeExpTesting ::FloatFastExpTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-3f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-4f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-5f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-6f);
    }
}

void Mathematics::FastNegativeExpTesting ::DoubleFastExpTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-3);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-4);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-5);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-6);
    }
}

void Mathematics::FastNegativeExpTesting ::FloatFastExpBoundaryTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetExponent(), MathF::maxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-8f);
    }
}

void Mathematics::FastNegativeExpTesting ::DoubleFastExpBoundaryTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetExponent(), MathD::maxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-10);
    }
}
