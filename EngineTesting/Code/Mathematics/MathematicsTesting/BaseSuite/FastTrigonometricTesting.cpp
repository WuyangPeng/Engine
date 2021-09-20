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

void Mathematics::FastTrigonometricTesting ::FloatFastSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ FloatMath::GetValue(0), FloatMath::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastSinRoughCalculation(value), sin(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastSinPreciseCalculation(value), sin(value), 1.0e-6f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastSinMorePreciseCalculation(value), sin(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(0), DoubleMath::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastSinRoughCalculation(value), sin(value), 1.0e-3);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastSinPreciseCalculation(value), sin(value), 1.0e-8);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastSinMorePreciseCalculation(value), sin(value), 1.0e-10);
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
    uniform_real<float> randomDistribution{ FloatMath::GetValue(0), FloatMath::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastCosRoughCalculation(value), cos(value), 1.0e-2f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastCosPreciseCalculation(value), cos(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastCosMorePreciseCalculation(value), cos(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(0), DoubleMath::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastCosRoughCalculation(value), cos(value), 1.0e-2);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastCosPreciseCalculation(value), cos(value), 1.0e-8);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastCosMorePreciseCalculation(value), cos(value), 1.0e-10);
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
    uniform_real<float> randomDistribution{ FloatMath::GetValue(0), FloatMath::GetQuarterPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastTanRoughCalculation(value), tan(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastTanPreciseCalculation(value), tan(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastTanMorePreciseCalculation(value), tan(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(0), DoubleMath::GetQuarterPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastTanRoughCalculation(value), tan(value), 1.0e-3);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastTanPreciseCalculation(value), tan(value), 1.0e-7);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastTanMorePreciseCalculation(value), tan(value), 1.0e-10);
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
    uniform_real<float> randomDistribution{ FloatMath::GetValue(0), FloatMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvSinRoughCalculation(value), asin(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvSinPreciseCalculation(value), asin(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvSinTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(0), DoubleMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvSinRoughCalculation(value), asin(value), 1.0e-4);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvSinPreciseCalculation(value), asin(value), 1.0e-7);
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
    uniform_real<float> randomDistribution{ FloatMath::GetValue(0), FloatMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvCosRoughCalculation(value), acos(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvCosPreciseCalculation(value), acos(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvCosTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(0), DoubleMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvCosRoughCalculation(value), acos(value), 1.0e-4);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvCosPreciseCalculation(value), acos(value), 1.0e-7);
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
    uniform_real<float> randomDistribution{ FloatMath::GetValue(-1), FloatMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvTanRoughCalculation(value), atan(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FloatFastTrigonometric::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting ::DoubleFastInvTanTest()
{
    // ÀÊª˙÷µ≤‚ ‘
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetValue(-1), DoubleMath::GetValue(1) };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvTanRoughCalculation(value), atan(value), 1.0e-4);

        ASSERT_APPROXIMATE(DoubleFastTrigonometric::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7);
    }
}
