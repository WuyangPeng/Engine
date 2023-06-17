///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:26)

#include "FastTrigonometricTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/FastTrigonometricDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class FastTrigonometric<float>;
    template class FastTrigonometric<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::FastTrigonometricTesting::FastTrigonometricTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, FastTrigonometricTesting)

void Mathematics::FastTrigonometricTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::FastTrigonometricTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FastSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FastInvTanTest);
}

void Mathematics::FastTrigonometricTesting::FastSinTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastSinTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastSinTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetHalfPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinRoughCalculation(value), sin(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinPreciseCalculation(value), sin(value), 1.0e-6f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastSinMorePreciseCalculation(value), sin(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastSinTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetHalfPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const double value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinRoughCalculation(value), sin(value), 1.0e-3);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinPreciseCalculation(value), sin(value), 1.0e-8);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastSinMorePreciseCalculation(value), sin(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting::FastCosTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastCosTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastCosTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetHalfPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosRoughCalculation(value), cos(value), 1.0e-2f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosPreciseCalculation(value), cos(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastCosMorePreciseCalculation(value), cos(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastCosTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetHalfPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosRoughCalculation(value), cos(value), 1.0e-2);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosPreciseCalculation(value), cos(value), 1.0e-8);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastCosMorePreciseCalculation(value), cos(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting::FastTanTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastTanTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastTanTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetQuarterPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanRoughCalculation(value), tan(value), 1.0e-3f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanPreciseCalculation(value), tan(value), 1.0e-7f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastTanMorePreciseCalculation(value), tan(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastTanTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetQuarterPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanRoughCalculation(value), tan(value), 1.0e-3);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanPreciseCalculation(value), tan(value), 1.0e-7);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastTanMorePreciseCalculation(value), tan(value), 1.0e-10);
    }
}

void Mathematics::FastTrigonometricTesting::FastInvSinTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvSinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvSinTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastInvSinTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvSinRoughCalculation(value), asin(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvSinPreciseCalculation(value), asin(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastInvSinTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvSinRoughCalculation(value), asin(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvSinPreciseCalculation(value), asin(value), 1.0e-7);
    }
}

void Mathematics::FastTrigonometricTesting::FastInvCosTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvCosTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvCosTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastInvCosTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvCosRoughCalculation(value), acos(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvCosPreciseCalculation(value), acos(value), 1.0e-6f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastInvCosTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvCosRoughCalculation(value), acos(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvCosPreciseCalculation(value), acos(value), 1.0e-7);
    }
}

void Mathematics::FastTrigonometricTesting::FastInvTanTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastInvTanTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastInvTanTest);
}

void Mathematics::FastTrigonometricTesting::FloatFastInvTanTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ MathF::GetValue(-1), MathF::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvTanRoughCalculation(value), atan(value), 1.0e-4f);

        ASSERT_APPROXIMATE(FastTrigonometricF::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7f);
    }
}

void Mathematics::FastTrigonometricTesting::DoubleFastInvTanTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ MathD::GetValue(-1), MathD::GetValue(1) };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvTanRoughCalculation(value), atan(value), 1.0e-4);

        ASSERT_APPROXIMATE(FastTrigonometricD::FastInvTanPreciseCalculation(value), atan(value), 1.0e-7);
    }
}
