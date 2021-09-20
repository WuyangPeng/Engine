// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/19 09:47)

#include "MathTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include "Mathematics/Rational/FloatingPointAnalysis.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

 

using std::numeric_limits;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, MathTesting)

void Mathematics::MathTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseMathTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TruncationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ApproximateTest);
}

// Constant测试
void Mathematics::MathTesting ::ConstantTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleConstantTest);
}

void Mathematics::MathTesting ::FloatConstantTest()
{
    constexpr auto pi = 3.14159265358979f;

    // 完整测试
    ASSERT_APPROXIMATE(FloatMath::sm_Epsilon, numeric_limits<float>::epsilon(), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetZeroTolerance(), numeric_limits<float>::epsilon(), 1.0e-6f);
    ASSERT_APPROXIMATE(FloatMath::sm_MaxReal, numeric_limits<float>::max(), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetExponent(), log(numeric_limits<float>::max()), 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::GetPI(), pi, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetTwoPI(), pi * 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetHalfPI(), pi / 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetQuarterPI(), pi / 4.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInversePI(), 1.0f / pi, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInverseTwoPI(), 0.5f / pi, 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::GetRadianToDegree(), 1.0f / FloatMath::GetDegreeToRadian(), 1.0e-5f);
    ASSERT_APPROXIMATE(FloatMath::GetDegreeToRadian(), 1.0f / FloatMath::GetRadianToDegree(), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetRadianToDegree(), 180.0f / pi, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetDegreeToRadian(), pi / 180.0f, 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::GetLN2(), log(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetLN10(), log(10.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInverseLN2(), 1.0f / log(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInverseLN10(), 1.0f / log(10.0f), 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::GetSqrt2(), sqrt(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInverseSqrt2(), 1.0f / sqrt(2.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetSqrt3(), sqrt(3.0f), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetInverseSqrt3(), 1.0f / sqrt(3.0f), 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::GetValue(0), 0.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetValue(1), 1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetValue(2), 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetValue(-1), -1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::GetRational(1, 3), 1.0f / 3.0f, 1.0e-8f);
}

void Mathematics::MathTesting ::DoubleConstantTest()
{
    constexpr auto pi = 3.14159265358979;

    // 完整测试
    ASSERT_APPROXIMATE(DoubleMath::sm_Epsilon, numeric_limits<double>::epsilon(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetZeroTolerance(), numeric_limits<double>::epsilon(), 1.0e-8);
    ASSERT_APPROXIMATE(DoubleMath::sm_MaxReal, numeric_limits<double>::max(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetExponent(), log(numeric_limits<double>::max()), 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::GetPI(), pi, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetTwoPI(), pi * 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(), pi / 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetQuarterPI(), pi / 4.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInversePI(), 1.0 / pi, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInverseTwoPI(), 0.5 / pi, 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::GetRadianToDegree(), 1.0 / DoubleMath::GetDegreeToRadian(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetDegreeToRadian(), 1.0 / DoubleMath::GetRadianToDegree(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetRadianToDegree(), 180.0 / pi, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetDegreeToRadian(), pi / 180.0, 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::GetLN2(), log(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetLN10(), log(10.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInverseLN2(), 1.0f / log(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInverseLN10(), 1.0f / log(10.0), 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::GetSqrt2(), sqrt(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInverseSqrt2(), 1.0 / sqrt(2.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetSqrt3(), sqrt(3.0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetInverseSqrt3(), 1.0 / sqrt(3.0), 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::GetValue(0), 0.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetValue(1), 1.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetValue(2), 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetValue(-1), -1.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::GetRational(1, 3), 1.0 / 3.0, 1.0e-10);
}

// Trigonometric测试
void Mathematics::MathTesting ::TrigonometricTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrigonometricBoundaryTest);
}

void Mathematics::MathTesting ::FloatTrigonometricTest()
{
    // 迭代测试
    const auto testLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, testLoopCount, "测试循环次数为零！");

    constexpr auto begin = -1.0f;
    constexpr auto end = 1.0f;
    auto step = (end - begin) / testLoopCount;

    default_random_engine randomEngine{};

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(FloatMath::ASin(value), asin(value), 1.0e-8f);
        ASSERT_APPROXIMATE(FloatMath::ACos(value), acos(value), 1.0e-8f);

        value += step;
    }

    // 随机值测试
    uniform_real<float> randomDistribution{ -FloatMath::sm_MaxReal / 100.0f, FloatMath::sm_MaxReal / 100.0f };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = randomDistribution(randomEngine);
        auto secondFloatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::ATan(firstFloatValue), atan(firstFloatValue), 1.0e-8f);

        if (FloatMath::sm_Epsilon < FloatMath::FAbs(firstFloatValue) || FloatMath::sm_Epsilon < FloatMath::FAbs(secondFloatValue))
        {
            ASSERT_APPROXIMATE(FloatMath::ATan2(firstFloatValue, secondFloatValue), atan2(firstFloatValue, secondFloatValue), 1.0e-8f);
        }
        else
        {
            ASSERT_APPROXIMATE(FloatMath::ATan2(firstFloatValue, secondFloatValue), FloatMath::GetValue(0), 1.0e-8f);
        }

        ASSERT_APPROXIMATE(FloatMath::Sin(firstFloatValue), sin(firstFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(FloatMath::Cos(secondFloatValue), cos(secondFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(FloatMath::Tan(secondFloatValue), tan(secondFloatValue), 1.0e-8f);
    }
}

void Mathematics::MathTesting ::DoubleTrigonometricTest()
{
    // 迭代测试
    const auto testLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, testLoopCount, "测试循环次数为零！");

    constexpr auto begin = -1.0;
    constexpr auto end = 1.0;
    auto step = (end - begin) / testLoopCount;

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(DoubleMath::ASin(value), asin(value), 1.0e-10);
        ASSERT_APPROXIMATE(DoubleMath::ACos(value), acos(value), 1.0e-10);

        value += step;
    }

    // 随机值测试
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ -DoubleMath::sm_MaxReal / 100.0, DoubleMath::sm_MaxReal / 100.0 };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstDoubleValue = randomDistribution(randomEngine);
        auto secondDoubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::ATan(firstDoubleValue), atan(firstDoubleValue), 1.0e-10);

        if (DoubleMath::sm_Epsilon < DoubleMath::FAbs(firstDoubleValue) || DoubleMath::sm_Epsilon < DoubleMath::FAbs(secondDoubleValue))
        {
            ASSERT_APPROXIMATE(DoubleMath::ATan2(firstDoubleValue, secondDoubleValue), atan2(firstDoubleValue, secondDoubleValue), 1.0e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(DoubleMath::ATan2(firstDoubleValue, secondDoubleValue), DoubleMath::GetValue(0), 1.0e-10);
        }

        ASSERT_APPROXIMATE(DoubleMath::Sin(firstDoubleValue), sin(firstDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(DoubleMath::Cos(secondDoubleValue), cos(secondDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(DoubleMath::Tan(secondDoubleValue), tan(secondDoubleValue), 1.0e-10);
    }
}

void Mathematics::MathTesting ::TrigonometricBoundaryTest()
{
    // 完整测试
    ASSERT_APPROXIMATE(FloatMath::ACos(-1.0f), FloatMath::GetPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::ACos(1.0f), FloatMath::GetValue(0), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::ASin(-1.0f), -FloatMath::GetHalfPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::ASin(1.0f), FloatMath::GetHalfPI(), 1.0e-8f);

    ASSERT_APPROXIMATE(DoubleMath::ACos(-1.0), DoubleMath::GetPI(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::ACos(1.0), DoubleMath::GetValue(0), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::ASin(-1.0), -DoubleMath::GetHalfPI(), 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::ASin(1.0), DoubleMath::GetHalfPI(), 1.0e-10);

    // 固定值测试
    ASSERT_APPROXIMATE(FloatMath::ATan2(0.0f, 0.0f), FloatMath::GetValue(0), 1.0e-8f);

    ASSERT_APPROXIMATE(DoubleMath::ATan2(0.0, 0.0), DoubleMath::GetValue(0), 1.0e-10);
}

// BaseMath测试
void Mathematics::MathTesting ::BaseMathTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatBaseMathTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleBaseMathTest);
}

void Mathematics::MathTesting ::FloatBaseMathTest()
{
    // 随机值测试
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ -FloatMath::sm_MaxReal / 100.0f, FloatMath::sm_MaxReal / 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = randomDistribution(randomEngine);
        auto secondFloatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Ceil(firstFloatValue), ceil(firstFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(FloatMath::FAbs(secondFloatValue), fabs(secondFloatValue), 1.0e-8f);

        ASSERT_APPROXIMATE(FloatMath::Floor(firstFloatValue), floor(firstFloatValue), 1.0e-8f);

        if (FloatMath::FAbs(secondFloatValue) <= FloatMath::sm_Epsilon)
        {
            secondFloatValue = FloatMath::sm_Epsilon * FloatMath::GetValue(2);
        }

        ASSERT_APPROXIMATE(FloatMath::FMod(firstFloatValue, secondFloatValue), fmod(firstFloatValue, secondFloatValue), 1.0e-8f);

        if (FloatMath::sm_Epsilon < firstFloatValue)
        {
            ASSERT_ENUM_EQUAL(FloatMath::Sign(firstFloatValue), NumericalValueSymbol::Positive);

            ASSERT_ENUM_EQUAL(FloatMath::Sign(-firstFloatValue), NumericalValueSymbol::Negative);
        }
        else if (firstFloatValue < -FloatMath::sm_Epsilon)
        {
            ASSERT_ENUM_EQUAL(FloatMath::Sign(firstFloatValue), NumericalValueSymbol::Negative);

            ASSERT_ENUM_EQUAL(FloatMath::Sign(-firstFloatValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(FloatMath::Sign(firstFloatValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting ::DoubleBaseMathTest()
{
    // 随机值测试
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ -DoubleMath::sm_MaxReal / 100.0, DoubleMath::sm_MaxReal / 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstDoubleValue = randomDistribution(randomEngine);
        auto secondDoubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Ceil(firstDoubleValue), ceil(firstDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(DoubleMath::FAbs(secondDoubleValue), fabs(secondDoubleValue), 1.0e-10);

        ASSERT_APPROXIMATE(DoubleMath::Floor(firstDoubleValue), floor(firstDoubleValue), 1.0e-8);

        if (DoubleMath::FAbs(secondDoubleValue) <= DoubleMath::sm_Epsilon)
        {
            secondDoubleValue = DoubleMath::sm_Epsilon * DoubleMath::GetValue(2);
        }

        ASSERT_APPROXIMATE(DoubleMath::FMod(firstDoubleValue, secondDoubleValue), fmod(firstDoubleValue, secondDoubleValue), 1.0e-10);

        if (DoubleMath::sm_Epsilon < firstDoubleValue)
        {
            ASSERT_ENUM_EQUAL(DoubleMath::Sign(firstDoubleValue), NumericalValueSymbol::Positive);

            ASSERT_ENUM_EQUAL(DoubleMath::Sign(-firstDoubleValue), NumericalValueSymbol::Negative);
        }
        else if (firstDoubleValue < -DoubleMath::sm_Epsilon)
        {
            ASSERT_ENUM_EQUAL(DoubleMath::Sign(firstDoubleValue), NumericalValueSymbol::Negative);

            ASSERT_ENUM_EQUAL(DoubleMath::Sign(-firstDoubleValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(DoubleMath::Sign(firstDoubleValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting ::BaseMathBoundaryTest()
{
    // 固定值测试
    ASSERT_ENUM_EQUAL(FloatMath::Sign(FloatMath::GetValue(0)), NumericalValueSymbol::Zero);

    ASSERT_ENUM_EQUAL(DoubleMath::Sign(DoubleMath::GetValue(0)), NumericalValueSymbol::Zero);
}

// Log测试
void Mathematics::MathTesting ::LogTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatLogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleLogTest);
}

void Mathematics::MathTesting ::FloatLogTest()
{
    // 随机值测试
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ FloatMath::GetZeroTolerance(), FloatMath::sm_MaxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float floatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Log(floatValue), log(floatValue), 1.0e-8f);
        ASSERT_APPROXIMATE(FloatMath::Log2(floatValue), log(floatValue) / log(2.0f), 1.0e-5f);
        ASSERT_APPROXIMATE(FloatMath::Log10(floatValue), log(floatValue) / log(10.0f), 1.0e-5f);
    }
}

void Mathematics::MathTesting ::DoubleLogTest()
{
    // 随机值测试
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ DoubleMath::GetZeroTolerance(), DoubleMath::sm_MaxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Log(doubleValue), log(doubleValue), 1.0e-10);
        ASSERT_APPROXIMATE(DoubleMath::Log2(doubleValue), log(doubleValue) / log(2.0), 1.0e-10);
        ASSERT_APPROXIMATE(DoubleMath::Log10(doubleValue), log(doubleValue) / log(10.0), 1.0e-10);
    }
}

// Pow测试
void Mathematics::MathTesting ::PowTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatPowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoublePowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PowBoundaryTest);
}

void Mathematics::MathTesting ::FloatPowTest()
{
    // 随机值测试
    default_random_engine randomEngine{};

    // 使用-FloatMath::sm_MaxReal至FloatMath::GetExponent()，
    // 会导致使用大量相同作用的负值进行测试。
    uniform_real<float> expRandomDistribution{ -FloatMath::GetExponent(), FloatMath::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float floatValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Exp(floatValue), exp(floatValue), 1.0e-8f);
    }

    uniform_real<float> positiveRandomDistribution{ FloatMath::GetZeroTolerance(), FloatMath::sm_MaxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = positiveRandomDistribution(randomEngine);

        uniform_real<float> powRandomDistribution{ -FloatMath::Log(FloatMath::sm_MaxReal) / FloatMath::Log(firstFloatValue),
                                                   FloatMath::Log(FloatMath::sm_MaxReal) / FloatMath::Log(firstFloatValue) };

        float secondFloatValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Pow(firstFloatValue, secondFloatValue), pow(firstFloatValue, secondFloatValue), 1.0e-8f);
    }

    uniform_real<float> sqrtRandomDistribution{ -FloatMath::Sqrt(FloatMath::sm_MaxReal), FloatMath::Sqrt(FloatMath::sm_MaxReal) };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto floatValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Square(floatValue), floatValue * floatValue, 1.0e-8f);
    }

    uniform_real<float> nonNegativeRandomDistribution{ FloatMath::GetValue(0), FloatMath::sm_MaxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = nonNegativeRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Sqrt(firstFloatValue), sqrt(firstFloatValue), 1.0e-8f);

        auto secondFloatValue = positiveRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::InvSqrt(secondFloatValue), 1.0f / sqrt(secondFloatValue), 1.0e-8f);

        auto cubeRoot = FloatMath::CubeRoot(firstFloatValue);

        if (0.0f <= cubeRoot)
        {
            ASSERT_APPROXIMATE(FloatMath::Pow(firstFloatValue, 1.0f / 3.0f), cubeRoot, 1.0e-8f);
        }
        else
        {
            ASSERT_APPROXIMATE(FloatMath::Pow(-firstFloatValue, 1.0f / 3.0f), -cubeRoot, 1.0e-8f);
        }
    }
}

void Mathematics::MathTesting ::DoublePowTest()
{
    // 随机值测试
    default_random_engine randomEngine{};

    uniform_real<double> expRandomDistribution{ -DoubleMath::GetExponent(), DoubleMath::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Exp(doubleValue), exp(doubleValue), 1.0e-10);
    }

    uniform_real<double> positiveRandomDistribution{ DoubleMath::GetZeroTolerance(), DoubleMath::sm_MaxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstDoubleValue = positiveRandomDistribution(randomEngine);

        uniform_real<double> powRandomDistribution{ -DoubleMath::Log(DoubleMath::sm_MaxReal) / DoubleMath::Log(firstDoubleValue),
                                                    DoubleMath::Log(DoubleMath::sm_MaxReal) / DoubleMath::Log(firstDoubleValue) };

        auto secondDoubleValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Pow(firstDoubleValue, secondDoubleValue), pow(firstDoubleValue, secondDoubleValue), 1.0e-10);
    }

    uniform_real<double> sqrtRandomDistribution{ -DoubleMath::Sqrt(DoubleMath::sm_MaxReal), DoubleMath::Sqrt(DoubleMath::sm_MaxReal) };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Square(doubleValue), doubleValue * doubleValue, 1.0e-10);
    }

    uniform_real<double> nonNegativeRandomDistribution{ DoubleMath::GetValue(0), DoubleMath::sm_MaxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = nonNegativeRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Sqrt(firstFloatValue), sqrt(firstFloatValue), 1.0e-10);

        auto secondDoubleValue = positiveRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::InvSqrt(secondDoubleValue), 1.0 / sqrt(secondDoubleValue), 1.0e-10);

        auto cubeRoot = DoubleMath::CubeRoot(firstFloatValue);

        if (0.0f <= cubeRoot)
        {
            ASSERT_APPROXIMATE(DoubleMath::Pow(firstFloatValue, 1.0 / 3.0), cubeRoot, 1.0e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(DoubleMath::Pow(-firstFloatValue, 1.0 / 3.0), -cubeRoot, 1.0e-10);
        }
    }
}

void Mathematics::MathTesting ::PowBoundaryTest()
{
    // 随机值测试
    default_random_engine randomEngine{};

    uniform_real<double> doubleRandomDistribution{ DoubleMath::sm_Epsilon, DoubleMath::sm_MaxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = doubleRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(DoubleMath::Pow(0.0, doubleValue), pow(0.0, doubleValue), 1.0e-10);
    }

    uniform_real<float> floatRandomDistribution{ FloatMath::sm_Epsilon, FloatMath::sm_MaxReal };

    for (auto loop = 0; loop < 1; ++loop)
    {
        auto floatValue = floatRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(FloatMath::Pow(0.0f, floatValue), pow(0.0f, floatValue), 1.0e-8f);
    }
}

void Mathematics::MathTesting ::TruncationTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTruncationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTruncationTest);
}

void Mathematics::MathTesting ::FloatTruncationTest()
{
    // 固定值测试

    ASSERT_APPROXIMATE(FloatMath::Clamp(-30.0f, -20.0f, 10.0f), -20.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::Clamp(40.0f, -10.0f, 30.0f), 30.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::Clamp(1.0f, -10.0f, 10.0f), 1.0f, 1.0e-8f);

    ASSERT_APPROXIMATE(FloatMath::Saturate(-0.4f), 0.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::Saturate(1.7f), 1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(FloatMath::Saturate(0.21f), 0.21f, 1.0e-8f);
}

void Mathematics::MathTesting ::DoubleTruncationTest()
{
    // 固定值测试

    ASSERT_APPROXIMATE(DoubleMath::Clamp(-20.0, -10.0, 10.0), -10.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::Clamp(20.0, -10.0, 10.0), 10.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::Clamp(0.0, -10.0, 10.0), 0.0, 1.0e-10);

    ASSERT_APPROXIMATE(DoubleMath::Saturate(-0.5), 0.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::Saturate(1.5), 1.0, 1.0e-10);
    ASSERT_APPROXIMATE(DoubleMath::Saturate(0.1), 0.1, 1.0e-10);
}

// Approximate测试
void Mathematics::MathTesting ::ApproximateTest()
{
    // 固定值测试
    ASSERT_TRUE(FloatMath::Approximate(0.001f, 0.002f, 0.001f));
    ASSERT_FALSE(FloatMath::Approximate(0.001f, 0.002f, 0.0001f));

    ASSERT_TRUE(DoubleMath::Approximate(0.0001, 0.0002, 0.0001));
    ASSERT_FALSE(DoubleMath::Approximate(0.0001, 0.0002, 0.00001));

    auto firstValue = 0.13124f;
    auto secondValue = 0.13241;

    ASSERT_TRUE(FloatMath::FloatingPointEqual(firstValue, firstValue, 23));
    ASSERT_TRUE(DoubleMath::FloatingPointEqual(secondValue, secondValue, 52));

    auto thirdValue = 0.13125f;
    auto fourthValue = 0.13244;

    ASSERT_TRUE(FloatMath::FloatingPointEqual(firstValue, thirdValue, 12));

    FloatingPointAnalysis<double> lhsAnalysis{ secondValue };
    FloatingPointAnalysis<double> rhsAnalysis{ fourthValue };

    ASSERT_TRUE(DoubleMath::FloatingPointEqual(secondValue, fourthValue, 11));
}
