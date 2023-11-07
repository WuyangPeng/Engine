///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:26)

#include "FastNegativeExpTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/FastNegativeExpDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class FastNegativeExp<float>;
    template class FastNegativeExp<double>;
}
#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::FastNegativeExpTesting::FastNegativeExpTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, FastNegativeExpTesting)

void Mathematics::FastNegativeExpTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::FastNegativeExpTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpBoundaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpBoundaryTest);
}

void Mathematics::FastNegativeExpTesting::FloatFastExpTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution{ MathF::GetValue(0), MathF::GetExponent() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const float value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-3f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-4f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-5f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-6f);
    }
}

void Mathematics::FastNegativeExpTesting::DoubleFastExpTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ MathD::GetValue(0), MathD::GetExponent() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-3);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-4);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-5);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-6);
    }
}

void Mathematics::FastNegativeExpTesting::FloatFastExpBoundaryTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution{ MathF::GetExponent(), MathF::maxReal };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-8f);
        ASSERT_APPROXIMATE(FastNegativeExpF::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-8f);
    }
}

void Mathematics::FastNegativeExpTesting::DoubleFastExpBoundaryTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ MathD::GetExponent(), MathD::maxReal };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMoreRoughCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpRoughCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpPreciseCalculation(value), exp(-value), 1.0e-10);
        ASSERT_APPROXIMATE(FastNegativeExpD::FastNegativeExpMorePreciseCalculation(value), exp(-value), 1.0e-10);
    }
}
