///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:27)

#include "MathTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysis.h"

#include <random>

Mathematics::MathTesting::MathTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MathTesting)

void Mathematics::MathTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MathTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseMathTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TruncationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ApproximateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NumberDigitsTest);
}

// Constant测试
void Mathematics::MathTesting::ConstantTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleConstantTest);
}

void Mathematics::MathTesting::FloatConstantTest()
{
    constexpr auto pi0 = 3.14159265358979f;

    // 完整测试
    ASSERT_APPROXIMATE(MathF::epsilon, std::numeric_limits<float>::epsilon(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetZeroTolerance(), std::numeric_limits<float>::epsilon(), 1.0e-6f);
    ASSERT_APPROXIMATE(MathF::maxReal, std::numeric_limits<float>::max(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetExponent(), log(std::numeric_limits<float>::max()), 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetPI(), pi0, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetTwoPI(), pi0 * 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetHalfPI(), pi0 / 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetQuarterPI(), pi0 / 4.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInversePI(), 1.0f / pi0, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseTwoPI(), 0.5f / pi0, 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetRadianToDegree(), 1.0f / MathF::GetDegreeToRadian(), 1.0e-5f);
    ASSERT_APPROXIMATE(MathF::GetDegreeToRadian(), 1.0f / MathF::GetRadianToDegree(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetRadianToDegree(), 180.0f / pi0, 1.0e-5f);
    ASSERT_APPROXIMATE(MathF::GetDegreeToRadian(), pi0 / 180.0f, 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetLN2(), log(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetLN10(), log(10.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseLN2(), 1.0f / log(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseLN10(), 1.0f / log(10.0f), 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetSqrt2(), sqrt(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseSqrt2(), 1.0f / sqrt(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetSqrt3(), sqrt(3.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseSqrt3(), 1.0f / sqrt(3.0f), 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetValue(0), 0.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetValue(1), 1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetValue(2), 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetValue(-1), -1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetRational(1, 3), 1.0f / 3.0f, 1.0e-8f);
}

void Mathematics::MathTesting::DoubleConstantTest()
{
    constexpr auto pi0 = 3.14159265358979;

    // 完整测试
    ASSERT_APPROXIMATE(MathD::epsilon, std::numeric_limits<double>::epsilon(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetZeroTolerance(), std::numeric_limits<double>::epsilon(), 1.0e-8);
    ASSERT_APPROXIMATE(MathD::maxReal, std::numeric_limits<double>::max(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetExponent(), log(std::numeric_limits<double>::max()), 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetPI(), pi0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetTwoPI(), pi0 * 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetHalfPI(), pi0 / 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetQuarterPI(), pi0 / 4.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInversePI(), 1.0 / pi0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseTwoPI(), 0.5 / pi0, 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetRadianToDegree(), 1.0 / MathD::GetDegreeToRadian(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetDegreeToRadian(), 1.0 / MathD::GetRadianToDegree(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetRadianToDegree(), 180.0 / pi0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetDegreeToRadian(), pi0 / 180.0, 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetLN2(), log(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetLN10(), log(10.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseLN2(), 1.0f / log(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseLN10(), 1.0f / log(10.0), 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetSqrt2(), sqrt(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseSqrt2(), 1.0 / sqrt(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetSqrt3(), sqrt(3.0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseSqrt3(), 1.0 / sqrt(3.0), 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetValue(0), 0.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetValue(1), 1.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetValue(2), 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetValue(-1), -1.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetRational(1, 3), 1.0 / 3.0, 1.0e-10);
}

// Trigonometric测试
void Mathematics::MathTesting::TrigonometricTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrigonometricBoundaryTest);
}

void Mathematics::MathTesting::FloatTrigonometricTest()
{
    // 迭代测试
    const auto aTestLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, aTestLoopCount, "测试循环次数为零！");

    constexpr auto begin = -1.0f;
    constexpr auto end = 1.0f;
    const auto step = (end - begin) / aTestLoopCount;

    std::default_random_engine randomEngine{ GetEngineRandomSeed() };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(MathF::ASin(value), asin(value), 1.0e-8f);
        ASSERT_APPROXIMATE(MathF::ACos(value), acos(value), 1.0e-8f);

        value += step;
    }

    // 随机值测试
    std::uniform_real_distribution<float> randomDistribution{ -MathF::maxReal / 100.0f, MathF::maxReal / 100.0f };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstFloatValue = randomDistribution(randomEngine);
        auto secondFloatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::ATan(firstFloatValue), atan(firstFloatValue), 1.0e-8f);

        if (MathF::epsilon < MathF::FAbs(firstFloatValue) || MathF::epsilon < MathF::FAbs(secondFloatValue))
        {
            ASSERT_APPROXIMATE(MathF::ATan2(firstFloatValue, secondFloatValue), atan2(firstFloatValue, secondFloatValue), 1.0e-8f);
        }
        else
        {
            ASSERT_APPROXIMATE(MathF::ATan2(firstFloatValue, secondFloatValue), MathF::GetValue(0), 1.0e-8f);
        }

        ASSERT_APPROXIMATE(MathF::Sin(firstFloatValue), sin(firstFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(MathF::Cos(secondFloatValue), cos(secondFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(MathF::Tan(secondFloatValue), tan(secondFloatValue), 1.0e-8f);
    }
}

void Mathematics::MathTesting::DoubleTrigonometricTest()
{
    // 迭代测试
    const auto aTestLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, aTestLoopCount, "测试循环次数为零！");

    constexpr auto begin = -1.0;
    constexpr auto end = 1.0;
    const auto step = (end - begin) / aTestLoopCount;

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(MathD::ASin(value), asin(value), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::ACos(value), acos(value), 1.0e-10);

        value += step;
    }

    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -MathD::maxReal / 100.0, MathD::maxReal / 100.0 };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstDoubleValue = randomDistribution(randomEngine);
        auto secondDoubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::ATan(firstDoubleValue), atan(firstDoubleValue), 1.0e-10);

        if (MathD::epsilon < MathD::FAbs(firstDoubleValue) || MathD::epsilon < MathD::FAbs(secondDoubleValue))
        {
            ASSERT_APPROXIMATE(MathD::ATan2(firstDoubleValue, secondDoubleValue), atan2(firstDoubleValue, secondDoubleValue), 1.0e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(MathD::ATan2(firstDoubleValue, secondDoubleValue), MathD::GetValue(0), 1.0e-10);
        }

        ASSERT_APPROXIMATE(MathD::Sin(firstDoubleValue), sin(firstDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(MathD::Cos(secondDoubleValue), cos(secondDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(MathD::Tan(secondDoubleValue), tan(secondDoubleValue), 1.0e-10);
    }
}

void Mathematics::MathTesting::TrigonometricBoundaryTest()
{
    // 完整测试
    ASSERT_APPROXIMATE(MathF::ACos(-1.0f), MathF::GetPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ACos(1.0f), MathF::GetValue(0), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ASin(-1.0f), -MathF::GetHalfPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ASin(1.0f), MathF::GetHalfPI(), 1.0e-8f);

    ASSERT_APPROXIMATE(MathD::ACos(-1.0), MathD::GetPI(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ACos(1.0), MathD::GetValue(0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ASin(-1.0), -MathD::GetHalfPI(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ASin(1.0), MathD::GetHalfPI(), 1.0e-10);

    // 固定值测试
    ASSERT_APPROXIMATE(MathF::ATan2(0.0f, 0.0f), MathF::GetValue(0), 1.0e-8f);

    ASSERT_APPROXIMATE(MathD::ATan2(0.0, 0.0), MathD::GetValue(0), 1.0e-10);
}

// BaseMath测试
void Mathematics::MathTesting::BaseMathTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatBaseMathTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleBaseMathTest);
}

void Mathematics::MathTesting::FloatBaseMathTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -MathF::maxReal / 100.0f, MathF::maxReal / 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstFloatValue = randomDistribution(randomEngine);
        auto secondFloatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Ceil(firstFloatValue), ceil(firstFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(MathF::FAbs(secondFloatValue), fabs(secondFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(MathF::Floor(firstFloatValue), floor(firstFloatValue), 1.0e-8f);

        if (MathF::FAbs(secondFloatValue) <= MathF::epsilon)
        {
            secondFloatValue = MathF::epsilon * MathF::GetValue(2);
        }

        ASSERT_APPROXIMATE(MathF::FMod(firstFloatValue, secondFloatValue), fmod(firstFloatValue, secondFloatValue), 1.0e-8f);

        if (MathF::epsilon < firstFloatValue)
        {
            ASSERT_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Positive);

            ASSERT_EQUAL(MathF::Sign(-firstFloatValue), NumericalValueSymbol::Negative);
        }
        else if (firstFloatValue < -MathF::epsilon)
        {
            ASSERT_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Negative);

            ASSERT_EQUAL(MathF::Sign(-firstFloatValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting::DoubleBaseMathTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -MathD::maxReal / 100.0, MathD::maxReal / 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstDoubleValue = randomDistribution(randomEngine);
        auto secondDoubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Ceil(firstDoubleValue), ceil(firstDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(MathD::FAbs(secondDoubleValue), fabs(secondDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(MathD::Floor(firstDoubleValue), floor(firstDoubleValue), 1.0e-8);

        if (MathD::FAbs(secondDoubleValue) <= MathD::epsilon)
        {
            secondDoubleValue = MathD::epsilon * MathD::GetValue(2);
        }

        ASSERT_APPROXIMATE(MathD::FMod(firstDoubleValue, secondDoubleValue), fmod(firstDoubleValue, secondDoubleValue), 1.0e-10);

        if (MathD::epsilon < firstDoubleValue)
        {
            ASSERT_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Positive);

            ASSERT_EQUAL(MathD::Sign(-firstDoubleValue), NumericalValueSymbol::Negative);
        }
        else if (firstDoubleValue < -MathD::epsilon)
        {
            ASSERT_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Negative);

            ASSERT_EQUAL(MathD::Sign(-firstDoubleValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting::BaseMathBoundaryTest()
{
    // 固定值测试
    ASSERT_EQUAL(MathF::Sign(MathF::GetValue(0)), NumericalValueSymbol::Zero);

    ASSERT_EQUAL(MathD::Sign(MathD::GetValue(0)), NumericalValueSymbol::Zero);
}

// Log测试
void Mathematics::MathTesting::LogTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatLogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleLogTest);
}

void Mathematics::MathTesting::FloatLogTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ MathF::GetZeroTolerance(), MathF::maxReal };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const float floatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Log(floatValue), log(floatValue), 1.0e-8f);
        ASSERT_APPROXIMATE(MathF::Log2(floatValue), log(floatValue) / log(2.0f), 1.0e-5f);
        ASSERT_APPROXIMATE(MathF::Log10(floatValue), log(floatValue) / log(10.0f), 1.0e-5f);
    }
}

void Mathematics::MathTesting::DoubleLogTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ MathD::GetZeroTolerance(), MathD::maxReal };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto doubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Log(doubleValue), log(doubleValue), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::Log2(doubleValue), log(doubleValue) / log(2.0), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::Log10(doubleValue), log(doubleValue) / log(10.0), 1.0e-10);
    }
}

// Pow测试
void Mathematics::MathTesting::PowTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatPowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoublePowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PowBoundaryTest);
}

void Mathematics::MathTesting::FloatPowTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };

    // 使用-MathF::sm_MaxReal至MathF::GetExponent()，
    // 会导致使用大量相同作用的负值进行测试。
    std::uniform_real_distribution<float> expRandomDistribution{ -MathF::GetExponent(), MathF::GetExponent() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const float floatValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Exp(floatValue), exp(floatValue), 1.0e-8f);
    }

    std::uniform_real_distribution<float> positiveRandomDistribution{ MathF::GetZeroTolerance(), MathF::maxReal };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstFloatValue = positiveRandomDistribution(randomEngine);

        std::uniform_real_distribution<float> powRandomDistribution{ -MathF::Log(MathF::maxReal) / MathF::Log(firstFloatValue),
                                                              MathF::Log(MathF::maxReal) / MathF::Log(firstFloatValue) };

        const float secondFloatValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Pow(firstFloatValue, secondFloatValue), pow(firstFloatValue, secondFloatValue), 1.0e-8f);
    }

    std::uniform_real_distribution<float> sqrtRandomDistribution{ -MathF::Sqrt(MathF::maxReal), MathF::Sqrt(MathF::maxReal) };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto floatValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Square(floatValue), floatValue * floatValue, 1.0e-8f);
    }

    std::uniform_real_distribution<float> nonNegativeRandomDistribution{ MathF::GetValue(0), MathF::maxReal };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstFloatValue = nonNegativeRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Sqrt(firstFloatValue), sqrt(firstFloatValue), 1.0e-8f);

        auto secondFloatValue = positiveRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::InvSqrt(secondFloatValue), 1.0f / sqrt(secondFloatValue), 1.0e-8f);

        auto cubeRoot = MathF::CubeRoot(firstFloatValue);

        if (0.0f <= cubeRoot)
        {
            ASSERT_APPROXIMATE(MathF::Pow(firstFloatValue, 1.0f / 3.0f), cubeRoot, 1.0e-8f);
        }
        else
        {
            ASSERT_APPROXIMATE(MathF::Pow(-firstFloatValue, 1.0f / 3.0f), -cubeRoot, 1.0e-8f);
        }
    }
}

void Mathematics::MathTesting::DoublePowTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> expRandomDistribution{ -MathD::GetExponent(), MathD::GetExponent() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto doubleValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Exp(doubleValue), exp(doubleValue), 1.0e-10);
    }

    std::uniform_real_distribution<double> positiveRandomDistribution{ MathD::GetZeroTolerance(), MathD::maxReal };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstDoubleValue = positiveRandomDistribution(randomEngine);

        std::uniform_real_distribution<double> powRandomDistribution{ -MathD::Log(MathD::maxReal) / MathD::Log(firstDoubleValue),
                                                               MathD::Log(MathD::maxReal) / MathD::Log(firstDoubleValue) };

        auto secondDoubleValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Pow(firstDoubleValue, secondDoubleValue), pow(firstDoubleValue, secondDoubleValue), 1.0e-10);
    }

    std::uniform_real_distribution<double> sqrtRandomDistribution{ -MathD::Sqrt(MathD::maxReal), MathD::Sqrt(MathD::maxReal) };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto doubleValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Square(doubleValue), doubleValue * doubleValue, 1.0e-10);
    }

    std::uniform_real_distribution<double> nonNegativeRandomDistribution{ MathD::GetValue(0), MathD::maxReal };

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstFloatValue = nonNegativeRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Sqrt(firstFloatValue), sqrt(firstFloatValue), 1.0e-10);

        auto secondDoubleValue = positiveRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::InvSqrt(secondDoubleValue), 1.0 / sqrt(secondDoubleValue), 1.0e-10);

        auto cubeRoot = MathD::CubeRoot(firstFloatValue);

        if (0.0f <= cubeRoot)
        {
            ASSERT_APPROXIMATE(MathD::Pow(firstFloatValue, 1.0 / 3.0), cubeRoot, 1.0e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(MathD::Pow(-firstFloatValue, 1.0 / 3.0), -cubeRoot, 1.0e-10);
        }
    }
}

void Mathematics::MathTesting::PowBoundaryTest()
{
    // 随机值测试
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> doubleRandomDistribution{ MathD::epsilon, MathD::maxReal };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto doubleValue = doubleRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Pow(0.0, doubleValue), pow(0.0, doubleValue), 1.0e-10);
    }

    std::uniform_real_distribution<float> floatRandomDistribution{ MathF::epsilon, MathF::maxReal };

    for (auto loop = 0; loop < 1; ++loop)
    {
        auto floatValue = floatRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Pow(0.0f, floatValue), pow(0.0f, floatValue), 1.0e-8f);
    }
}

void Mathematics::MathTesting::TruncationTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTruncationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTruncationTest);
}

void Mathematics::MathTesting::FloatTruncationTest()
{
    // 固定值测试

    ASSERT_APPROXIMATE(MathF::Clamp(-30.0f, -20.0f, 10.0f), -20.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Clamp(40.0f, -10.0f, 30.0f), 30.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Clamp(1.0f, -10.0f, 10.0f), 1.0f, 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::Saturate(-0.4f), 0.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Saturate(1.7f), 1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Saturate(0.21f), 0.21f, 1.0e-8f);
}

void Mathematics::MathTesting::DoubleTruncationTest()
{
    // 固定值测试

    ASSERT_APPROXIMATE(MathD::Clamp(-20.0, -10.0, 10.0), -10.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Clamp(20.0, -10.0, 10.0), 10.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Clamp(0.0, -10.0, 10.0), 0.0, 1.0e-10);

    ASSERT_APPROXIMATE(MathD::Saturate(-0.5), 0.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Saturate(1.5), 1.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Saturate(0.1), 0.1, 1.0e-10);
}

// Approximate测试
void Mathematics::MathTesting::ApproximateTest()
{
    // 固定值测试
    ASSERT_TRUE(MathF::Approximate(0.001f, 0.002f, 0.001f));
    ASSERT_FALSE(MathF::Approximate(0.001f, 0.002f, 0.0001f));

    ASSERT_TRUE(MathD::Approximate(0.0001, 0.0002, 0.0001));
    ASSERT_FALSE(MathD::Approximate(0.0001, 0.0002, 0.00001));

    constexpr auto firstValue = 0.13124f;
    constexpr auto secondValue = 0.13241;

    ASSERT_TRUE(MathF::FloatingPointEqual(firstValue, firstValue, 23));
    ASSERT_TRUE(MathD::FloatingPointEqual(secondValue, secondValue, 52));

    constexpr auto thirdValue = 0.13125f;
    constexpr auto fourthValue = 0.13244;

    ASSERT_TRUE(MathF::FloatingPointEqual(firstValue, thirdValue, 12));

    const FloatingPointAnalysis<double> lhsAnalysis{ secondValue };
    const FloatingPointAnalysis<double> rhsAnalysis{ fourthValue };

    ASSERT_TRUE(MathD::FloatingPointEqual(secondValue, fourthValue, 11));
}

void Mathematics::MathTesting::NumberDigitsTest()
{
    for (auto index = 1LL; index <= std::numeric_limits<int64_t>::max() && 0 < index; index *= 10)
    {
        for (auto i = index; i < index * 10; i += index)
        {
            auto digits = i;
            auto result = 0;

            while (0 < digits)
            {
                constexpr auto base = 10;

                digits /= base;
                ++result;
            }

            ASSERT_EQUAL(MathF::GetNumberDigits(i), result);
        }
    }
}