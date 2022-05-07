// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/19 09:47)

#include "MathTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include "Mathematics/Rational/FloatingPointAnalysis.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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

// Constant����
void Mathematics::MathTesting ::ConstantTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleConstantTest);
}

void Mathematics::MathTesting ::FloatConstantTest()
{
    constexpr auto pi = 3.14159265358979f;
    
    // ��������
    ASSERT_APPROXIMATE(MathF::epsilon, numeric_limits<float>::epsilon(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetZeroTolerance(), numeric_limits<float>::epsilon(), 1.0e-6f);
    ASSERT_APPROXIMATE(MathF::maxReal, numeric_limits<float>::max(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetExponent(), log(numeric_limits<float>::max()), 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetPI(), pi, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetTwoPI(), pi * 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetHalfPI(), pi / 2.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetQuarterPI(), pi / 4.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInversePI(), 1.0f / pi, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetInverseTwoPI(), 0.5f / pi, 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::GetRadianToDegree(), 1.0f / MathF::GetDegreeToRadian(), 1.0e-5f);
    ASSERT_APPROXIMATE(MathF::GetDegreeToRadian(), 1.0f / MathF::GetRadianToDegree(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::GetRadianToDegree(), 180.0f / pi, 1.0e-5f);
    ASSERT_APPROXIMATE(MathF::GetDegreeToRadian(), pi / 180.0f, 1.0e-8f);

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

void Mathematics::MathTesting ::DoubleConstantTest()
{
    constexpr auto pi = 3.14159265358979;

    // ��������
    ASSERT_APPROXIMATE(MathD::epsilon, numeric_limits<double>::epsilon(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetZeroTolerance(), numeric_limits<double>::epsilon(), 1.0e-8);
    ASSERT_APPROXIMATE(MathD::maxReal, numeric_limits<double>::max(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetExponent(), log(numeric_limits<double>::max()), 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetPI(), pi, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetTwoPI(), pi * 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetHalfPI(), pi / 2.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetQuarterPI(), pi / 4.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInversePI(), 1.0 / pi, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetInverseTwoPI(), 0.5 / pi, 1.0e-10);

    ASSERT_APPROXIMATE(MathD::GetRadianToDegree(), 1.0 / MathD::GetDegreeToRadian(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetDegreeToRadian(), 1.0 / MathD::GetRadianToDegree(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetRadianToDegree(), 180.0 / pi, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::GetDegreeToRadian(), pi / 180.0, 1.0e-10);

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

// Trigonometric����
void Mathematics::MathTesting ::TrigonometricTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTrigonometricTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrigonometricBoundaryTest);
}

void Mathematics::MathTesting ::FloatTrigonometricTest()
{
    // ��������
    const auto testLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, testLoopCount, "����ѭ������Ϊ�㣡");

    constexpr auto begin = -1.0f;
    constexpr auto end = 1.0f;
    auto step = (end - begin) / testLoopCount;

    default_random_engine randomEngine{};

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(MathF::ASin(value), asin(value), 1.0e-8f);
        ASSERT_APPROXIMATE(MathF::ACos(value), acos(value), 1.0e-8f);

        value += step;
    }

    // ���ֵ����
    uniform_real<float> randomDistribution{ -MathF::maxReal / 100.0f, MathF::maxReal / 100.0f };

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

void Mathematics::MathTesting ::DoubleTrigonometricTest()
{
    // ��������
    const auto testLoopCount = GetTestLoopCount();

    ASSERT_LESS_EQUAL_FAILURE_THROW(0, testLoopCount, "����ѭ������Ϊ�㣡");

    constexpr auto begin = -1.0;
    constexpr auto end = 1.0;
    auto step = (end - begin) / testLoopCount;

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = begin;

        ASSERT_APPROXIMATE(MathD::ASin(value), asin(value), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::ACos(value), acos(value), 1.0e-10);

        value += step;
    }

    // ���ֵ����
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ -MathD::maxReal / 100.0, MathD::maxReal / 100.0 };

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

void Mathematics::MathTesting ::TrigonometricBoundaryTest()
{
    // ��������
    ASSERT_APPROXIMATE(MathF::ACos(-1.0f), MathF::GetPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ACos(1.0f), MathF::GetValue(0), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ASin(-1.0f), -MathF::GetHalfPI(), 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::ASin(1.0f), MathF::GetHalfPI(), 1.0e-8f);

    ASSERT_APPROXIMATE(MathD::ACos(-1.0), MathD::GetPI(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ACos(1.0), MathD::GetValue(0), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ASin(-1.0), -MathD::GetHalfPI(), 1.0e-10);
    ASSERT_APPROXIMATE(MathD::ASin(1.0), MathD::GetHalfPI(), 1.0e-10);

    // �̶�ֵ����
    ASSERT_APPROXIMATE(MathF::ATan2(0.0f, 0.0f), MathF::GetValue(0), 1.0e-8f);

    ASSERT_APPROXIMATE(MathD::ATan2(0.0, 0.0), MathD::GetValue(0), 1.0e-10);
}

// BaseMath����
void Mathematics::MathTesting ::BaseMathTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatBaseMathTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleBaseMathTest);
}

void Mathematics::MathTesting ::FloatBaseMathTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ -MathF::maxReal / 100.0f, MathF::maxReal / 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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
            ASSERT_ENUM_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Positive);

            ASSERT_ENUM_EQUAL(MathF::Sign(-firstFloatValue), NumericalValueSymbol::Negative);
        }
        else if (firstFloatValue < -MathF::epsilon)
        {
            ASSERT_ENUM_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Negative);

            ASSERT_ENUM_EQUAL(MathF::Sign(-firstFloatValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(MathF::Sign(firstFloatValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting ::DoubleBaseMathTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ -MathD::maxReal / 100.0, MathD::maxReal / 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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
            ASSERT_ENUM_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Positive);

            ASSERT_ENUM_EQUAL(MathD::Sign(-firstDoubleValue), NumericalValueSymbol::Negative);
        }
        else if (firstDoubleValue < -MathD::epsilon)
        {
            ASSERT_ENUM_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Negative);

            ASSERT_ENUM_EQUAL(MathD::Sign(-firstDoubleValue), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(MathD::Sign(firstDoubleValue), NumericalValueSymbol::Zero);
        }
    }
}

void Mathematics::MathTesting ::BaseMathBoundaryTest()
{
    // �̶�ֵ����
    ASSERT_ENUM_EQUAL(MathF::Sign(MathF::GetValue(0)), NumericalValueSymbol::Zero);

    ASSERT_ENUM_EQUAL(MathD::Sign(MathD::GetValue(0)), NumericalValueSymbol::Zero);
}

// Log����
void Mathematics::MathTesting ::LogTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatLogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleLogTest);
}

void Mathematics::MathTesting ::FloatLogTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};
    uniform_real<float> randomDistribution{ MathF::GetZeroTolerance(), MathF::maxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float floatValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Log(floatValue), log(floatValue), 1.0e-8f);
        ASSERT_APPROXIMATE(MathF::Log2(floatValue), log(floatValue) / log(2.0f), 1.0e-5f);
        ASSERT_APPROXIMATE(MathF::Log10(floatValue), log(floatValue) / log(10.0f), 1.0e-5f);
    }
}

void Mathematics::MathTesting ::DoubleLogTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};
    uniform_real<double> randomDistribution{ MathD::GetZeroTolerance(), MathD::maxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = randomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Log(doubleValue), log(doubleValue), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::Log2(doubleValue), log(doubleValue) / log(2.0), 1.0e-10);
        ASSERT_APPROXIMATE(MathD::Log10(doubleValue), log(doubleValue) / log(10.0), 1.0e-10);
    }
}

// Pow����
void Mathematics::MathTesting ::PowTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatPowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoublePowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PowBoundaryTest);
}

void Mathematics::MathTesting ::FloatPowTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};

    // ʹ��-FloatMath::sm_MaxReal��FloatMath::GetExponent()��
    // �ᵼ��ʹ�ô�����ͬ���õĸ�ֵ���в��ԡ�
    uniform_real<float> expRandomDistribution{ -MathF::GetExponent(), MathF::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float floatValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Exp(floatValue), exp(floatValue), 1.0e-8f);
    }

    uniform_real<float> positiveRandomDistribution{ MathF::GetZeroTolerance(), MathF::maxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstFloatValue = positiveRandomDistribution(randomEngine);

        uniform_real<float> powRandomDistribution{ -MathF::Log(MathF::maxReal) / MathF::Log(firstFloatValue),
                                                   MathF::Log(MathF::maxReal) / MathF::Log(firstFloatValue) };

        float secondFloatValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Pow(firstFloatValue, secondFloatValue), pow(firstFloatValue, secondFloatValue), 1.0e-8f);
    }

    uniform_real<float> sqrtRandomDistribution{ -MathF::Sqrt(MathF::maxReal), MathF::Sqrt(MathF::maxReal) };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto floatValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Square(floatValue), floatValue * floatValue, 1.0e-8f);
    }

    uniform_real<float> nonNegativeRandomDistribution{ MathF::GetValue(0), MathF::maxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

void Mathematics::MathTesting ::DoublePowTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};

    uniform_real<double> expRandomDistribution{ -MathD::GetExponent(), MathD::GetExponent() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = expRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Exp(doubleValue), exp(doubleValue), 1.0e-10);
    }

    uniform_real<double> positiveRandomDistribution{ MathD::GetZeroTolerance(), MathD::maxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto firstDoubleValue = positiveRandomDistribution(randomEngine);

        uniform_real<double> powRandomDistribution{ -MathD::Log(MathD::maxReal) / MathD::Log(firstDoubleValue),
                                                    MathD::Log(MathD::maxReal) / MathD::Log(firstDoubleValue) };

        auto secondDoubleValue = powRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Pow(firstDoubleValue, secondDoubleValue), pow(firstDoubleValue, secondDoubleValue), 1.0e-10);
    }

    uniform_real<double> sqrtRandomDistribution{ -MathD::Sqrt(MathD::maxReal), MathD::Sqrt(MathD::maxReal) };

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = sqrtRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Square(doubleValue), doubleValue * doubleValue, 1.0e-10);
    }

    uniform_real<double> nonNegativeRandomDistribution{ MathD::GetValue(0), MathD::maxReal };

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

void Mathematics::MathTesting ::PowBoundaryTest()
{
    // ���ֵ����
    default_random_engine randomEngine{};

    uniform_real<double> doubleRandomDistribution{ MathD::epsilon, MathD::maxReal };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto doubleValue = doubleRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathD::Pow(0.0, doubleValue), pow(0.0, doubleValue), 1.0e-10);
    }

    uniform_real<float> floatRandomDistribution{ MathF::epsilon, MathF::maxReal };

    for (auto loop = 0; loop < 1; ++loop)
    {
        auto floatValue = floatRandomDistribution(randomEngine);

        ASSERT_APPROXIMATE(MathF::Pow(0.0f, floatValue), pow(0.0f, floatValue), 1.0e-8f);
    }
}

void Mathematics::MathTesting ::TruncationTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTruncationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTruncationTest);
}

void Mathematics::MathTesting ::FloatTruncationTest()
{
    // �̶�ֵ����

    ASSERT_APPROXIMATE(MathF::Clamp(-30.0f, -20.0f, 10.0f), -20.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Clamp(40.0f, -10.0f, 30.0f), 30.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Clamp(1.0f, -10.0f, 10.0f), 1.0f, 1.0e-8f);

    ASSERT_APPROXIMATE(MathF::Saturate(-0.4f), 0.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Saturate(1.7f), 1.0f, 1.0e-8f);
    ASSERT_APPROXIMATE(MathF::Saturate(0.21f), 0.21f, 1.0e-8f);
}

void Mathematics::MathTesting ::DoubleTruncationTest()
{
    // �̶�ֵ����

    ASSERT_APPROXIMATE(MathD::Clamp(-20.0, -10.0, 10.0), -10.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Clamp(20.0, -10.0, 10.0), 10.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Clamp(0.0, -10.0, 10.0), 0.0, 1.0e-10);

    ASSERT_APPROXIMATE(MathD::Saturate(-0.5), 0.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Saturate(1.5), 1.0, 1.0e-10);
    ASSERT_APPROXIMATE(MathD::Saturate(0.1), 0.1, 1.0e-10);
}

// Approximate����
void Mathematics::MathTesting ::ApproximateTest()
{
    // �̶�ֵ����
    ASSERT_TRUE(MathF::Approximate(0.001f, 0.002f, 0.001f));
    ASSERT_FALSE(MathF::Approximate(0.001f, 0.002f, 0.0001f));

    ASSERT_TRUE(MathD::Approximate(0.0001, 0.0002, 0.0001));
    ASSERT_FALSE(MathD::Approximate(0.0001, 0.0002, 0.00001));

    auto firstValue = 0.13124f;
    auto secondValue = 0.13241;

    ASSERT_TRUE(MathF::FloatingPointEqual(firstValue, firstValue, 23));
    ASSERT_TRUE(MathD::FloatingPointEqual(secondValue, secondValue, 52));

    auto thirdValue = 0.13125f;
    auto fourthValue = 0.13244;

    ASSERT_TRUE(MathF::FloatingPointEqual(firstValue, thirdValue, 12));

    FloatingPointAnalysis<double> lhsAnalysis{ secondValue };
    FloatingPointAnalysis<double> rhsAnalysis{ fourthValue };

    ASSERT_TRUE(MathD::FloatingPointEqual(secondValue, fourthValue, 11));
}