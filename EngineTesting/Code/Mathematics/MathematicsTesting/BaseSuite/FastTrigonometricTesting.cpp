// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 13:02)

#include "FastTrigonometricTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/FastTrigonometricDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class FastTrigonometric<float>;
    template class FastTrigonometric<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, FastTrigonometricTesting)

void Mathematics::FastTrigonometricTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FastSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvTanTest);
}

void Mathematics::FastTrigonometricTesting ::FastSinTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastSinTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::FastTrigonometricTesting ::FloatFastSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinRoughCalculation(value), sin(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinPreciseCalculation(value), sin(value), 1.0e-6f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinMorePreciseCalculation(value), sin(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinRoughCalculation(value), sin(value), 1.0e-3);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinPreciseCalculation(value), sin(value), 1.0e-8);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinMorePreciseCalculation(value), sin(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting ::FastCosTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastCosTest);
}

void Mathematics::FastTrigonometricTesting ::FloatFastCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosRoughCalculation(value), cos(value), 1.0e-2f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosPreciseCalculation(value), cos(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosMorePreciseCalculation(value), cos(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosRoughCalculation(value), cos(value), 1.0e-2);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosPreciseCalculation(value), cos(value), 1.0e-8);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosMorePreciseCalculation(value), cos(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting ::FastTanTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastTanTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetQuarterPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanRoughCalculation(value), tan(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanPreciseCalculation(value), tan(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanMorePreciseCalculation(value), tan(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetQuarterPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanRoughCalculation(value), tan(value), 1.0e-3);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanPreciseCalculation(value), tan(value), 1.0e-7);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanMorePreciseCalculation(value), tan(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting ::FastInvSinTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvSinTest);
}

void Mathematics::FastTrigonometricTesting ::FloatFastInvSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvSinRoughCalculation(value), asin(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvSinPreciseCalculation(value), asin(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvSinRoughCalculation(value), asin(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvSinPreciseCalculation(value), asin(value), 1.0e-7);
    }
}

void Mathematics::FastTrigonometricTesting ::FastInvCosTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvCosTest);
}

void Mathematics::FastTrigonometricTesting ::FloatFastInvCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvCosRoughCalculation(value), acos(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvCosPreciseCalculation(value), acos(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvCosRoughCalculation(value), acos(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvCosPreciseCalculation(value), acos(value), 1.0e-7);
    }
}

void Mathematics::FastTrigonometricTesting ::FastInvTanTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvTanTest);
}

void Mathematics::FastTrigonometricTesting ::FloatFastInvTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetValue(-1), MathF::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvTanRoughCalculation(value), atan(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetValue(-1), MathD::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvTanRoughCalculation(value), atan(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7);
    }
}
