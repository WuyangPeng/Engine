///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:30)

#include "FloatingPointAnalysisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"

#include <random>

namespace Mathematics
{
    template class FloatingPointAnalysis<float>;
    template class FloatingPointAnalysis<double>;
}

Mathematics::FloatingPointAnalysisTesting::FloatingPointAnalysisTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, FloatingPointAnalysisTesting)

void Mathematics::FloatingPointAnalysisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::FloatingPointAnalysisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTypeTest);
}

void Mathematics::FloatingPointAnalysisTesting::NumericalValueSymbolTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real_distribution<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real_distribution<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    std::uniform_real_distribution<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        auto secondValue = randomDistribution1(generator);
        const FloatingPointAnalysis<double> secondFloatingPointAnalysis(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        auto thirdValue = thirdRandomDistribution(generator);
        const FloatingPointAnalysis<float> thirdFloatingPointAnalysis(thirdValue);

        if (0.0 <= thirdValue)
        {
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        auto fourthValue = fourthRandomDistribution(generator);
        const FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        if (0.0 <= fourthValue)
        {
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbolValue(), 1u);
        }
    }
}

void Mathematics::FloatingPointAnalysisTesting::ExponentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real_distribution<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real_distribution<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    std::uniform_real_distribution<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        const auto firstRealExponent = firstFloatingPointAnalysis.GetRealExponent();
        auto secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        const FloatingPointAnalysis<float> secondFloatingPointAnalysis(secondValue);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetExponent(), secondFloatingPointAnalysis.GetExponent());

        ASSERT_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealExponent(), secondFloatingPointAnalysis.GetRealExponent());

        auto thirdValue = randomDistribution1(generator);
        const FloatingPointAnalysis<double> thirdFloatingPointAnalysis(thirdValue);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        const auto secondRealExponent = thirdFloatingPointAnalysis.GetRealExponent();
        auto fourthValue = MathD::Pow(2, static_cast<double>(secondRealExponent));
        const FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetExponent(), fourthFloatingPointAnalysis.GetExponent());

        ASSERT_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealExponent(), fourthFloatingPointAnalysis.GetRealExponent());

        auto fifthValue = thirdRandomDistribution(generator);
        const FloatingPointAnalysis<float> fifthFloatingPointAnalysis(fifthValue);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        const auto thirdRealExponent = fifthFloatingPointAnalysis.GetRealExponent();
        auto sixthValue = MathF::Pow(2, static_cast<float>(thirdRealExponent));
        const FloatingPointAnalysis<float> sixthFloatingPointAnalysis(sixthValue);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetExponent(), sixthFloatingPointAnalysis.GetExponent());

        ASSERT_EQUAL(sixthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealExponent(), sixthFloatingPointAnalysis.GetRealExponent());

        auto seventhValue = fourthRandomDistribution(generator);
        const FloatingPointAnalysis<double> seventhFloatingPointAnalysis(seventhValue);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        const auto eighthRealExponent = seventhFloatingPointAnalysis.GetRealExponent();
        auto eighthValue = MathD::Pow(2, static_cast<double>(eighthRealExponent));
        const FloatingPointAnalysis<double> eighthFloatingPointAnalysis(eighthValue);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetExponent(), eighthFloatingPointAnalysis.GetExponent());

        ASSERT_EQUAL(eighthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealExponent(), eighthFloatingPointAnalysis.GetRealExponent());
    }
}

void Mathematics::FloatingPointAnalysisTesting::MantissaTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real_distribution<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real_distribution<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    std::uniform_real_distribution<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);
    const std::uniform_int_distribution<> fifthRandomDistribution(0, 38);
    const std::uniform_int_distribution<> sixthRandomDistribution(0, 308);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        auto firstExponent = firstFloatingPointAnalysis.GetRealExponent();
        auto firstMantissa = firstFloatingPointAnalysis.GetRealMantissa();
        auto firstSign = firstFloatingPointAnalysis.GetSymbol();

        auto secondValue = static_cast<float>(firstMantissa) /
                           MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) *
                           MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        const FloatingPointAnalysis<float> secondFloatingPointAnalysis(secondValue);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbol(), secondFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealExponent(), secondFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealMantissa(), secondFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetMantissa(), secondFloatingPointAnalysis.GetMantissa());

        auto thirdValue = randomDistribution1(generator);
        const FloatingPointAnalysis<double> thirdFloatingPointAnalysis(thirdValue);

        auto secondExponent = thirdFloatingPointAnalysis.GetRealExponent();
        auto secondMantissa = thirdFloatingPointAnalysis.GetRealMantissa();
        auto secondSign = thirdFloatingPointAnalysis.GetSymbol();

        auto fourthValue = static_cast<double>(secondMantissa) /
                           MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) *
                           MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        const FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), fourthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealExponent(), fourthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealMantissa(), fourthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetMantissa(), fourthFloatingPointAnalysis.GetMantissa());

        auto fifthValue = thirdRandomDistribution(generator);
        const FloatingPointAnalysis<float> fifthFloatingPointAnalysis(fifthValue);

        firstExponent = -fifthFloatingPointAnalysis.GetRealExponent();
        firstMantissa = fifthFloatingPointAnalysis.GetRealMantissa();
        firstSign = fifthFloatingPointAnalysis.GetSymbol();

        auto sixthValue = static_cast<float>(firstMantissa) /
                          MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) /
                          MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            sixthValue = -sixthValue;

        const FloatingPointAnalysis<float> sixthFloatingPointAnalysis(sixthValue);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetSymbol(), sixthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealExponent(), sixthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealMantissa(), sixthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetMantissa(), sixthFloatingPointAnalysis.GetMantissa());

        auto seventhValue = fourthRandomDistribution(generator);
        const FloatingPointAnalysis<double> seventhFloatingPointAnalysis(seventhValue);

        secondExponent = -seventhFloatingPointAnalysis.GetRealExponent();
        secondMantissa = seventhFloatingPointAnalysis.GetRealMantissa();
        secondSign = seventhFloatingPointAnalysis.GetSymbol();

        auto eighthValue = static_cast<double>(secondMantissa) /
                           MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) /
                           MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            eighthValue = -eighthValue;

        const FloatingPointAnalysis<double> eighthFloatingPointAnalysis(eighthValue);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetSymbol(), eighthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealExponent(), eighthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealMantissa(), eighthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetMantissa(), eighthFloatingPointAnalysis.GetMantissa());
    }
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

void Mathematics::FloatingPointAnalysisTesting::FloatTypeTest()
{
    constexpr uint32_t firstValue = 0x7F800500;
    constexpr uint32_t secondValue = 0x7FC10500;
    constexpr uint32_t thirdValue = 0x7F800000;
    constexpr uint32_t fourthValue = 0x000E0809;

    auto fifthValue = *reinterpret_cast<const float*>(&firstValue);
    MAYBE_UNUSED const auto signalValue = *reinterpret_cast<const uint32_t*>(&fifthValue);

    const FloatingPointAnalysis<float> firstFloatingPointAnalysis(fifthValue);

#ifdef _DEBUG

    if (firstValue == signalValue)
    {
        // 有些编译器不支持SignalingNaN
        ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
    }
    else
    {
        ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);
    }

#else  // !_DEBUG

    ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);

#endif  // _DEBUG

    fifthValue = *reinterpret_cast<const float*>(&secondValue);

    const FloatingPointAnalysis<float> secondFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);

    fifthValue = *reinterpret_cast<const float*>(&thirdValue);

    const FloatingPointAnalysis<float> thirdFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Infinity);

    fifthValue = *reinterpret_cast<const float*>(&fourthValue);

    const FloatingPointAnalysis<float> fourthFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Zero);
}

void Mathematics::FloatingPointAnalysisTesting::DoubleTypeTest()
{
    constexpr uint64_t firstValue = (0x7FF0000000100000ULL);
    constexpr uint64_t secondValue = (0x7FF8000000000001ULL);
    constexpr uint64_t thirdValue = (0x7FF0000000000000ULL);
    constexpr uint64_t fourthValue = (0x000000000EE00000ULL);

    auto fifthValue = *reinterpret_cast<const double*>(&firstValue);
    MAYBE_UNUSED const auto signalValue = *reinterpret_cast<const uint64_t*>(&fifthValue);

    const FloatingPointAnalysis<double> firstFloatingPointAnalysis(fifthValue);

#ifdef _DEBUG

    if (firstValue == signalValue)
    {
        ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
    }
    else
    {
        ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);
    }

#else  // !_DEBUG

    ASSERT_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);

#endif  // _DEBUG

    fifthValue = *reinterpret_cast<const double*>(&secondValue);

    const FloatingPointAnalysis<double> secondFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);

    fifthValue = *reinterpret_cast<const double*>(&thirdValue);

    const FloatingPointAnalysis<double> thirdFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Infinity);

    fifthValue = *reinterpret_cast<const double*>(&fourthValue);

    const FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fifthValue);

    ASSERT_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Zero);
}

#include SYSTEM_WARNING_POP