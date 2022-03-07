// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:22)

#include "FloatingPointAnalysisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class FloatingPointAnalysis<float>;
    template class FloatingPointAnalysis<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, FloatingPointAnalysisTesting)

void Mathematics::FloatingPointAnalysisTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTypeTest);
}

void Mathematics::FloatingPointAnalysisTesting ::NumericalValueSymbolTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float firstValue = firstRandomDistribution(generator);
        FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(firstFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        double secondValue = secondRandomDistribution(generator);
        FloatingPointAnalysis<double> secondFloatingPointAnalysis(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_ENUM_EQUAL(secondFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_ENUM_EQUAL(secondFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(secondFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        float thirdValue = thirdRandomDistribution(generator);
        FloatingPointAnalysis<float> thirdFloatingPointAnalysis(thirdValue);

        if (0.0 <= thirdValue)
        {
            ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(thirdFloatingPointAnalysis.GetSymbolValue(), 1u);
        }

        double fourthValue = fourthRandomDistribution(generator);
        FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        if (0.0 <= fourthValue)
        {
            ASSERT_ENUM_EQUAL(fourthFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Positive);
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbolValue(), 0u);
        }
        else
        {
            ASSERT_ENUM_EQUAL(fourthFloatingPointAnalysis.GetSymbol(), NumericalValueSymbol::Negative);
            ASSERT_EQUAL(fourthFloatingPointAnalysis.GetSymbolValue(), 1u);
        }
    }
}

void Mathematics::FloatingPointAnalysisTesting ::ExponentTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float firstValue = firstRandomDistribution(generator);
        FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        int firstRealExponent = firstFloatingPointAnalysis.GetRealExponent();
        float secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        FloatingPointAnalysis<float> secondFloatingPointAnalysis(secondValue);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetExponent(), secondFloatingPointAnalysis.GetExponent());

        ASSERT_ENUM_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealExponent(), secondFloatingPointAnalysis.GetRealExponent());

        double thirdValue = secondRandomDistribution(generator);
        FloatingPointAnalysis<double> thirdFloatingPointAnalysis(thirdValue);

        ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        int secondRealExponent = thirdFloatingPointAnalysis.GetRealExponent();
        double fourthValue = MathD::Pow(2, static_cast<double>(secondRealExponent));
        FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetExponent(), fourthFloatingPointAnalysis.GetExponent());

        ASSERT_ENUM_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealExponent(), fourthFloatingPointAnalysis.GetRealExponent());

        float fifthValue = thirdRandomDistribution(generator);
        FloatingPointAnalysis<float> fifthFloatingPointAnalysis(fifthValue);

        ASSERT_ENUM_EQUAL(fifthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        int thirdRealExponent = fifthFloatingPointAnalysis.GetRealExponent();
        float sixthValue = MathF::Pow(2, static_cast<float>(thirdRealExponent));
        FloatingPointAnalysis<float> sixthFloatingPointAnalysis(sixthValue);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetExponent(), sixthFloatingPointAnalysis.GetExponent());

        ASSERT_ENUM_EQUAL(sixthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealExponent(), sixthFloatingPointAnalysis.GetRealExponent());

        double seventhValue = fourthRandomDistribution(generator);
        FloatingPointAnalysis<double> seventhFloatingPointAnalysis(seventhValue);

        ASSERT_ENUM_EQUAL(seventhFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        int eighthRealExponent = seventhFloatingPointAnalysis.GetRealExponent();
        double eighthValue = MathD::Pow(2, static_cast<double>(eighthRealExponent));
        FloatingPointAnalysis<double> eighthFloatingPointAnalysis(eighthValue);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetExponent(), eighthFloatingPointAnalysis.GetExponent());

        ASSERT_ENUM_EQUAL(eighthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Valid);

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealExponent(), eighthFloatingPointAnalysis.GetRealExponent());
    }
}

void Mathematics::FloatingPointAnalysisTesting ::MantissaTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);
    uniform_int<> fifthRandomDistribution(0, 38);
    uniform_int<> sixthRandomDistribution(0, 308);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float firstValue = firstRandomDistribution(generator);
        FloatingPointAnalysis<float> firstFloatingPointAnalysis(firstValue);

        int firstExponent = firstFloatingPointAnalysis.GetRealExponent();
        uint32_t firstMantissa = firstFloatingPointAnalysis.GetRealMantissa();
        NumericalValueSymbol firstSign = firstFloatingPointAnalysis.GetSymbol();

        float secondValue = static_cast<float>(firstMantissa) / MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) *
                            MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        FloatingPointAnalysis<float> secondFloatingPointAnalysis(secondValue);

        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetSymbol(), secondFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealExponent(), secondFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetRealMantissa(), secondFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(firstFloatingPointAnalysis.GetMantissa(), secondFloatingPointAnalysis.GetMantissa());

        double thirdValue = secondRandomDistribution(generator);
        FloatingPointAnalysis<double> thirdFloatingPointAnalysis(thirdValue);

        int secondExponent = thirdFloatingPointAnalysis.GetRealExponent();
        uint64_t secondMantissa = thirdFloatingPointAnalysis.GetRealMantissa();
        NumericalValueSymbol secondSign = thirdFloatingPointAnalysis.GetSymbol();

        double fourthValue = static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) *
                             MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fourthValue);

        ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetSymbol(), fourthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealExponent(), fourthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetRealMantissa(), fourthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(thirdFloatingPointAnalysis.GetMantissa(), fourthFloatingPointAnalysis.GetMantissa());

        float fifthValue = thirdRandomDistribution(generator);
        FloatingPointAnalysis<float> fifthFloatingPointAnalysis(fifthValue);

        firstExponent = -fifthFloatingPointAnalysis.GetRealExponent();
        firstMantissa = fifthFloatingPointAnalysis.GetRealMantissa();
        firstSign = fifthFloatingPointAnalysis.GetSymbol();

        float sixthValue = static_cast<float>(firstMantissa) / MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) /
                           MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            sixthValue = -sixthValue;

        FloatingPointAnalysis<float> sixthFloatingPointAnalysis(sixthValue);

        ASSERT_ENUM_EQUAL(fifthFloatingPointAnalysis.GetSymbol(), sixthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealExponent(), sixthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetRealMantissa(), sixthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(fifthFloatingPointAnalysis.GetMantissa(), sixthFloatingPointAnalysis.GetMantissa());

        double seventhValue = fourthRandomDistribution(generator);
        FloatingPointAnalysis<double> seventhFloatingPointAnalysis(seventhValue);

        secondExponent = -seventhFloatingPointAnalysis.GetRealExponent();
        secondMantissa = seventhFloatingPointAnalysis.GetRealMantissa();
        secondSign = seventhFloatingPointAnalysis.GetSymbol();

        double eighthValue = static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) /
                             MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            eighthValue = -eighthValue;

        FloatingPointAnalysis<double> eighthFloatingPointAnalysis(eighthValue);

        ASSERT_ENUM_EQUAL(seventhFloatingPointAnalysis.GetSymbol(), eighthFloatingPointAnalysis.GetSymbol());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealExponent(), eighthFloatingPointAnalysis.GetRealExponent());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetRealMantissa(), eighthFloatingPointAnalysis.GetRealMantissa());

        ASSERT_EQUAL(seventhFloatingPointAnalysis.GetMantissa(), eighthFloatingPointAnalysis.GetMantissa());
    }
}

void Mathematics::FloatingPointAnalysisTesting ::FloatTypeTest()
{
    uint32_t firstValue = 0x7F800500;
    uint32_t secondValue = 0x7FC10500;
    uint32_t thirdValue = 0x7F800000;
    uint32_t fourthValue = 0x000E0809;

    float fifthValue = *reinterpret_cast<float*>(&firstValue);
    uint32_t signalValue = *reinterpret_cast<uint32_t*>(&fifthValue);

    FloatingPointAnalysis<float> firstFloatingPointAnalysis(fifthValue);

#ifdef _DEBUG
    if (firstValue == signalValue)
    {
        // ”––©±‡“Î∆˜≤ª÷ß≥÷SignalingNaN
        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
    }
    else
    {
        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);
    }
#else  // !_DEBUG
    signalValue;
    ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
#endif  // _DEBUG

    fifthValue = *reinterpret_cast<float*>(&secondValue);

    FloatingPointAnalysis<float> secondFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);

    fifthValue = *reinterpret_cast<float*>(&thirdValue);

    FloatingPointAnalysis<float> thirdFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Infinity);

    fifthValue = *reinterpret_cast<float*>(&fourthValue);

    FloatingPointAnalysis<float> fourthFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Zero);
}

void Mathematics::FloatingPointAnalysisTesting ::DoubleTypeTest()
{
    uint64_t firstValue = (0x7FF0000000100000ULL);
    uint64_t secondValue = (0x7FF8000000000001ULL);
    uint64_t thirdValue = (0x7FF0000000000000ULL);
    uint64_t fourthValue = (0x000000000EE00000ULL);

    double fifthValue = *reinterpret_cast<double*>(&firstValue);
    uint64_t signalValue = *reinterpret_cast<uint64_t*>(&fifthValue);

    FloatingPointAnalysis<double> firstFloatingPointAnalysis(fifthValue);

#ifdef _DEBUG
    if (firstValue == signalValue)
    {
        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
    }
    else
    {
        ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);
    }
#else  // !_DEBUG
    signalValue;
    ASSERT_ENUM_EQUAL(firstFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::SignalingNaN);
#endif  // _DEBUG

    fifthValue = *reinterpret_cast<double*>(&secondValue);

    FloatingPointAnalysis<double> secondFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(secondFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::QuietNaN);

    fifthValue = *reinterpret_cast<double*>(&thirdValue);

    FloatingPointAnalysis<double> thirdFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(thirdFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Infinity);

    fifthValue = *reinterpret_cast<double*>(&fourthValue);

    FloatingPointAnalysis<double> fourthFloatingPointAnalysis(fifthValue);

    ASSERT_ENUM_EQUAL(fourthFloatingPointAnalysis.GetType(), FloatingPointAnalysisType::Zero);
}
