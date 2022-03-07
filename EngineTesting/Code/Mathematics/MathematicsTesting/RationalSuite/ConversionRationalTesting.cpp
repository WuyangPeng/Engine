// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:15)

#include "ConversionRationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/Log2OfPowerOfTwoDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/ConversionRationalDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <random>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ConversionRationalTesting)

void Mathematics::ConversionRationalTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
}

void Mathematics::ConversionRationalTesting ::NumericalValueSymbolTest()
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
        ConversionRational<float> firstConversionRational(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_ENUM_EQUAL(firstConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        double secondValue = secondRandomDistribution(generator);
        ConversionRational<double> secondConversionRational(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_ENUM_EQUAL(secondConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(secondConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        float thirdValue = thirdRandomDistribution(generator);
        ConversionRational<float> thirdConversionRational(thirdValue);

        if (0.0 <= thirdValue)
        {
            ASSERT_ENUM_EQUAL(thirdConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(thirdConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        double fourthValue = fourthRandomDistribution(generator);
        ConversionRational<double> fourthConversionRational(fourthValue);

        if (0.0 <= fourthValue)
        {
            ASSERT_ENUM_EQUAL(fourthConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(fourthConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }
    }
}

void Mathematics::ConversionRationalTesting ::ExponentTest()
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
        ConversionRational<float> firstConversionRational(firstValue);

        int firstRealExponent = firstConversionRational.GetNumeratorShifting();
        float secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        ConversionRational<float> secondIntegerConversion(secondValue);

        ASSERT_EQUAL(firstConversionRational.GetNumeratorShifting(), secondIntegerConversion.GetNumeratorShifting());

        ASSERT_THREE_EQUAL(firstConversionRational.GetDenominatorShifting(), secondIntegerConversion.GetDenominatorShifting(), 0);

        ASSERT_THREE_EQUAL(firstConversionRational.GetMaxShifting(), secondIntegerConversion.GetMaxShifting(), firstConversionRational.GetNumeratorShifting() + 23);

        int shifting = 23 - firstConversionRational.GetNumeratorShifting();

        if (shifting < 0)
        {
            shifting = 0;
        }

        ASSERT_THREE_EQUAL(firstConversionRational.GetReducibilityShifting(), secondIntegerConversion.GetReducibilityShifting(), shifting);

        double thirdValue = secondRandomDistribution(generator);
        ConversionRational<double> thirdConversionRational(thirdValue);

        int secondRealExponent = thirdConversionRational.GetNumeratorShifting();
        double fourthValue = MathD::Pow(2, static_cast<double>(secondRealExponent));
        ConversionRational<double> fourthIntegerConversion(fourthValue);

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorShifting(), fourthIntegerConversion.GetNumeratorShifting());

        ASSERT_THREE_EQUAL(thirdConversionRational.GetDenominatorShifting(), fourthIntegerConversion.GetDenominatorShifting(), 0);

        ASSERT_THREE_EQUAL(thirdConversionRational.GetMaxShifting(), fourthIntegerConversion.GetMaxShifting(), thirdConversionRational.GetNumeratorShifting() + 52);

        shifting = 52 - thirdConversionRational.GetNumeratorShifting();

        if (shifting < 0)
        {
            shifting = 0;
        }

        ASSERT_THREE_EQUAL(thirdConversionRational.GetReducibilityShifting(), fourthIntegerConversion.GetReducibilityShifting(), shifting);

        float fifthValue = thirdRandomDistribution(generator);
        ConversionRational<float> fifthConversionRational(fifthValue);

        int thirdRealExponent = fifthConversionRational.GetDenominatorShifting();
        float sixthValue = MathF::Pow(2, static_cast<float>(-thirdRealExponent));
        ConversionRational<float> sixthIntegerConversion(sixthValue);

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorShifting(),
                     sixthIntegerConversion.GetDenominatorShifting());

        ASSERT_THREE_EQUAL(fifthConversionRational.GetNumeratorShifting(), sixthIntegerConversion.GetNumeratorShifting(), 0);

        ASSERT_THREE_EQUAL(fifthConversionRational.GetMaxShifting(), sixthIntegerConversion.GetMaxShifting(), fifthConversionRational.GetDenominatorShifting() + 23);

        ASSERT_THREE_EQUAL(fifthConversionRational.GetReducibilityShifting(), sixthIntegerConversion.GetReducibilityShifting(), -23);

        double seventhValue = fourthRandomDistribution(generator);
        ConversionRational<double> seventhConversionRational(seventhValue);

        int fourthRealExponent = seventhConversionRational.GetDenominatorShifting();
        double eighthValue = MathD::Pow(2, static_cast<double>(-fourthRealExponent));
        ConversionRational<double> eighthIntegerConversion(eighthValue);

        ASSERT_EQUAL(seventhConversionRational.GetDenominatorShifting(), eighthIntegerConversion.GetDenominatorShifting());

        ASSERT_THREE_EQUAL(seventhConversionRational.GetNumeratorShifting(), eighthIntegerConversion.GetNumeratorShifting(), 0);

        ASSERT_THREE_EQUAL(seventhConversionRational.GetMaxShifting(), eighthIntegerConversion.GetMaxShifting(),
                           seventhConversionRational.GetDenominatorShifting() + 52);

        ASSERT_THREE_EQUAL(seventhConversionRational.GetReducibilityShifting(), eighthIntegerConversion.GetReducibilityShifting(), -52);
    }
}

void Mathematics::ConversionRationalTesting ::MantissaTest()
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
        ConversionRational<float> firstConversionRational(firstValue);

        int firstExponent = firstConversionRational.GetNumeratorShifting();
        uint64_t firstMantissa = firstConversionRational.GetNumeratorMantissa();
        NumericalValueSymbol firstSign = firstConversionRational.GetSymbol();
        uint64_t firstDenominatorMantissa = firstConversionRational.GetDenominatorMantissa();

        float secondValue = static_cast<float>(firstMantissa) / firstDenominatorMantissa * MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        ConversionRational<float> secondConversionRational(secondValue);

        ASSERT_ENUM_EQUAL(firstConversionRational.GetSymbol(), secondConversionRational.GetSymbol());

        ASSERT_EQUAL(firstConversionRational.GetNumeratorShifting(), secondConversionRational.GetNumeratorShifting());

        ASSERT_EQUAL(firstConversionRational.GetNumeratorMantissa(), secondConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(firstConversionRational.GetDenominatorMantissa(), secondConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(firstConversionRational.GetDenominatorShifting(), secondConversionRational.GetDenominatorShifting(), 0);

        double thirdValue = secondRandomDistribution(generator);
        ConversionRational<double> thirdConversionRational(thirdValue);

        int secondExponent = thirdConversionRational.GetNumeratorShifting();
        uint64_t secondMantissa = thirdConversionRational.GetNumeratorMantissa();
        NumericalValueSymbol secondSign = thirdConversionRational.GetSymbol();
        uint64_t secondDenominatorMantissa = thirdConversionRational.GetDenominatorMantissa();

        double fourthValue = static_cast<double>(secondMantissa) / secondDenominatorMantissa * MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        ConversionRational<double> fourthConversionRational(fourthValue);

        ASSERT_ENUM_EQUAL(thirdConversionRational.GetSymbol(), fourthConversionRational.GetSymbol());

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorShifting(), fourthConversionRational.GetNumeratorShifting());

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorMantissa(), fourthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(thirdConversionRational.GetDenominatorMantissa(), fourthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(thirdConversionRational.GetDenominatorShifting(), fourthConversionRational.GetDenominatorShifting(), 0);

        float fifthValue = thirdRandomDistribution(generator);
        ConversionRational<float> fifthConversionRational(fifthValue);

        firstExponent = fifthConversionRational.GetDenominatorShifting();
        firstMantissa = fifthConversionRational.GetDenominatorMantissa();
        firstSign = fifthConversionRational.GetSymbol();
        uint64_t firstNumeratorMantissa = fifthConversionRational.GetNumeratorMantissa();

        float sixthValue = firstNumeratorMantissa / static_cast<float>(firstMantissa) / MathF::Pow(2.0, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            sixthValue = -sixthValue;

        ConversionRational<float> sixthConversionRational(sixthValue);

        ASSERT_ENUM_EQUAL(fifthConversionRational.GetSymbol(), sixthConversionRational.GetSymbol());

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorShifting(), sixthConversionRational.GetDenominatorShifting());

        ASSERT_EQUAL(fifthConversionRational.GetNumeratorMantissa(), sixthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorMantissa(), sixthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(fifthConversionRational.GetNumeratorShifting(), sixthConversionRational.GetNumeratorShifting(), 0);

        double seventhValue = fourthRandomDistribution(generator);
        ConversionRational<double> seventhIntegerConversion(seventhValue);

        secondExponent = seventhIntegerConversion.GetDenominatorShifting();
        secondMantissa = seventhIntegerConversion.GetDenominatorMantissa();
        secondSign = seventhIntegerConversion.GetSymbol();
        uint64_t secondNumeratorMantissa = seventhIntegerConversion.GetNumeratorMantissa();

        double eighthValue = secondNumeratorMantissa / static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            eighthValue = -eighthValue;

        ConversionRational<double> eighthConversionRational(eighthValue);

        ASSERT_ENUM_EQUAL(seventhIntegerConversion.GetSymbol(), eighthConversionRational.GetSymbol());

        ASSERT_EQUAL(seventhIntegerConversion.GetDenominatorShifting(), eighthConversionRational.GetDenominatorShifting());

        ASSERT_EQUAL(seventhIntegerConversion.GetNumeratorMantissa(), eighthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(seventhIntegerConversion.GetDenominatorMantissa(), eighthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(seventhIntegerConversion.GetNumeratorShifting(), eighthConversionRational.GetNumeratorShifting(), 0);
    }
}

void Mathematics::ConversionRationalTesting ::IntegerTest()
{
    ConversionRational<int> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorMantissa(), 20);
    ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(static_cast<uint32_t>(firstIntegerConversion.GetMaxShifting()), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetReducibilityShifting(), 0);

    ConversionRational<int16_t> secondIntegerConversion(-120);

    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorMantissa(), 120);
    ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(static_cast<uint32_t>(secondIntegerConversion.GetMaxShifting()), Log2OfPowerOfTwo<uint32_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetReducibilityShifting(), 0);

    ConversionRational<int64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorMantissa(), 0);
    ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(thirdIntegerConversion.GetMaxShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetReducibilityShifting(), 0);
}

void Mathematics::ConversionRationalTesting ::UnsignedIntegerTest()
{
    ConversionRational<uint32_t> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorMantissa(), 20);
    ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(static_cast<uint32_t>(firstIntegerConversion.GetMaxShifting()), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetReducibilityShifting(), 0);

    ConversionRational<uint8_t> secondIntegerConversion(120);

    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorMantissa(), 120);
    ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(static_cast<uint8_t>(secondIntegerConversion.GetMaxShifting()), Log2OfPowerOfTwo<uint8_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetReducibilityShifting(), 0);

    ConversionRational<uint64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorMantissa(), 0);
    ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(thirdIntegerConversion.GetMaxShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetReducibilityShifting(), 0);
}
