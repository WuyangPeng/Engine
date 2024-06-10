///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:30)

#include "ConversionRationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Log2OfPowerOfTwoDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/ConversionRationalDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <random>

Mathematics::ConversionRationalTesting::ConversionRationalTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ConversionRationalTesting)

void Mathematics::ConversionRationalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ConversionRationalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
}

void Mathematics::ConversionRationalTesting::NumericalValueSymbolTest()
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
        const ConversionRational<float> firstConversionRational(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_EQUAL(firstConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(firstConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto secondValue = randomDistribution1(generator);
        const ConversionRational<double> secondConversionRational(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_EQUAL(secondConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(secondConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto thirdValue = thirdRandomDistribution(generator);
        const ConversionRational<float> thirdConversionRational(thirdValue);

        if (0.0 <= thirdValue)
        {
            ASSERT_EQUAL(thirdConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(thirdConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto fourthValue = fourthRandomDistribution(generator);
        const ConversionRational<double> fourthConversionRational(fourthValue);

        if (0.0 <= fourthValue)
        {
            ASSERT_EQUAL(fourthConversionRational.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(fourthConversionRational.GetSymbol(), NumericalValueSymbol::Negative);
        }
    }
}

void Mathematics::ConversionRationalTesting::ExponentTest()
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
        const ConversionRational<float> firstConversionRational(firstValue);

        const auto firstRealExponent = firstConversionRational.GetNumeratorShifting();
        auto secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        const ConversionRational<float> secondIntegerConversion(secondValue);

        ASSERT_EQUAL(firstConversionRational.GetNumeratorShifting(), secondIntegerConversion.GetNumeratorShifting());

        ASSERT_THREE_EQUAL(firstConversionRational.GetDenominatorShifting(), secondIntegerConversion.GetDenominatorShifting(), 0);

        ASSERT_THREE_EQUAL(firstConversionRational.GetMaxShifting(), secondIntegerConversion.GetMaxShifting(), firstConversionRational.GetNumeratorShifting() + 23);

        auto shifting = 23 - firstConversionRational.GetNumeratorShifting();

        if (shifting < 0)
        {
            shifting = 0;
        }

        ASSERT_THREE_EQUAL(firstConversionRational.GetReducibilityShifting(), secondIntegerConversion.GetReducibilityShifting(), shifting);

        auto thirdValue = randomDistribution1(generator);
        const ConversionRational<double> thirdConversionRational(thirdValue);

        const auto secondRealExponent = thirdConversionRational.GetNumeratorShifting();
        auto fourthValue = MathD::Pow(2, static_cast<double>(secondRealExponent));
        const ConversionRational<double> fourthIntegerConversion(fourthValue);

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorShifting(), fourthIntegerConversion.GetNumeratorShifting());

        ASSERT_THREE_EQUAL(thirdConversionRational.GetDenominatorShifting(), fourthIntegerConversion.GetDenominatorShifting(), 0);

        ASSERT_THREE_EQUAL(thirdConversionRational.GetMaxShifting(), fourthIntegerConversion.GetMaxShifting(), thirdConversionRational.GetNumeratorShifting() + 52);

        shifting = 52 - thirdConversionRational.GetNumeratorShifting();

        if (shifting < 0)
        {
            shifting = 0;
        }

        ASSERT_THREE_EQUAL(thirdConversionRational.GetReducibilityShifting(), fourthIntegerConversion.GetReducibilityShifting(), shifting);

        auto fifthValue = thirdRandomDistribution(generator);
        const ConversionRational<float> fifthConversionRational(fifthValue);

        const auto thirdRealExponent = fifthConversionRational.GetDenominatorShifting();
        auto sixthValue = MathF::Pow(2, static_cast<float>(-thirdRealExponent));
        const ConversionRational<float> sixthIntegerConversion(sixthValue);

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorShifting(),
                     sixthIntegerConversion.GetDenominatorShifting());

        ASSERT_THREE_EQUAL(fifthConversionRational.GetNumeratorShifting(), sixthIntegerConversion.GetNumeratorShifting(), 0);

        ASSERT_THREE_EQUAL(fifthConversionRational.GetMaxShifting(), sixthIntegerConversion.GetMaxShifting(), fifthConversionRational.GetDenominatorShifting() + 23);

        ASSERT_THREE_EQUAL(fifthConversionRational.GetReducibilityShifting(), sixthIntegerConversion.GetReducibilityShifting(), -23);

        auto seventhValue = fourthRandomDistribution(generator);
        const ConversionRational<double> seventhConversionRational(seventhValue);

        const auto fourthRealExponent = seventhConversionRational.GetDenominatorShifting();
        auto eighthValue = MathD::Pow(2, static_cast<double>(-fourthRealExponent));
        const ConversionRational<double> eighthIntegerConversion(eighthValue);

        ASSERT_EQUAL(seventhConversionRational.GetDenominatorShifting(), eighthIntegerConversion.GetDenominatorShifting());

        ASSERT_THREE_EQUAL(seventhConversionRational.GetNumeratorShifting(), eighthIntegerConversion.GetNumeratorShifting(), 0);

        ASSERT_THREE_EQUAL(seventhConversionRational.GetMaxShifting(),
                           eighthIntegerConversion.GetMaxShifting(),
                           seventhConversionRational.GetDenominatorShifting() + 52);

        ASSERT_THREE_EQUAL(seventhConversionRational.GetReducibilityShifting(), eighthIntegerConversion.GetReducibilityShifting(), -52);
    }
}

void Mathematics::ConversionRationalTesting::MantissaTest()
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
        const ConversionRational<float> firstConversionRational(firstValue);

        auto firstExponent = firstConversionRational.GetNumeratorShifting();
        auto firstMantissa = firstConversionRational.GetNumeratorMantissa();
        auto firstSign = firstConversionRational.GetSymbol();
        const auto firstDenominatorMantissa = firstConversionRational.GetDenominatorMantissa();

        auto secondValue = static_cast<float>(firstMantissa) / firstDenominatorMantissa * MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        const ConversionRational<float> secondConversionRational(secondValue);

        ASSERT_EQUAL(firstConversionRational.GetSymbol(), secondConversionRational.GetSymbol());

        ASSERT_EQUAL(firstConversionRational.GetNumeratorShifting(), secondConversionRational.GetNumeratorShifting());

        ASSERT_EQUAL(firstConversionRational.GetNumeratorMantissa(), secondConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(firstConversionRational.GetDenominatorMantissa(), secondConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(firstConversionRational.GetDenominatorShifting(), secondConversionRational.GetDenominatorShifting(), 0);

        auto thirdValue = randomDistribution1(generator);
        const ConversionRational<double> thirdConversionRational(thirdValue);

        auto secondExponent = thirdConversionRational.GetNumeratorShifting();
        auto secondMantissa = thirdConversionRational.GetNumeratorMantissa();
        auto secondSign = thirdConversionRational.GetSymbol();
        const auto secondDenominatorMantissa = thirdConversionRational.GetDenominatorMantissa();

        auto fourthValue = static_cast<double>(secondMantissa) / secondDenominatorMantissa * MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        const ConversionRational<double> fourthConversionRational(fourthValue);

        ASSERT_EQUAL(thirdConversionRational.GetSymbol(), fourthConversionRational.GetSymbol());

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorShifting(), fourthConversionRational.GetNumeratorShifting());

        ASSERT_EQUAL(thirdConversionRational.GetNumeratorMantissa(), fourthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(thirdConversionRational.GetDenominatorMantissa(), fourthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(thirdConversionRational.GetDenominatorShifting(), fourthConversionRational.GetDenominatorShifting(), 0);

        auto fifthValue = thirdRandomDistribution(generator);
        const ConversionRational<float> fifthConversionRational(fifthValue);

        firstExponent = fifthConversionRational.GetDenominatorShifting();
        firstMantissa = fifthConversionRational.GetDenominatorMantissa();
        firstSign = fifthConversionRational.GetSymbol();
        const auto firstNumeratorMantissa = fifthConversionRational.GetNumeratorMantissa();

        auto sixthValue = firstNumeratorMantissa / static_cast<float>(firstMantissa) / MathF::Pow(2.0, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            sixthValue = -sixthValue;

        const ConversionRational<float> sixthConversionRational(sixthValue);

        ASSERT_EQUAL(fifthConversionRational.GetSymbol(), sixthConversionRational.GetSymbol());

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorShifting(), sixthConversionRational.GetDenominatorShifting());

        ASSERT_EQUAL(fifthConversionRational.GetNumeratorMantissa(), sixthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(fifthConversionRational.GetDenominatorMantissa(), sixthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(fifthConversionRational.GetNumeratorShifting(), sixthConversionRational.GetNumeratorShifting(), 0);

        auto seventhValue = fourthRandomDistribution(generator);
        const ConversionRational<double> seventhIntegerConversion(seventhValue);

        secondExponent = seventhIntegerConversion.GetDenominatorShifting();
        secondMantissa = seventhIntegerConversion.GetDenominatorMantissa();
        secondSign = seventhIntegerConversion.GetSymbol();
        const auto secondNumeratorMantissa = seventhIntegerConversion.GetNumeratorMantissa();

        auto eighthValue = secondNumeratorMantissa / static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            eighthValue = -eighthValue;

        const ConversionRational<double> eighthConversionRational(eighthValue);

        ASSERT_EQUAL(seventhIntegerConversion.GetSymbol(), eighthConversionRational.GetSymbol());

        ASSERT_EQUAL(seventhIntegerConversion.GetDenominatorShifting(), eighthConversionRational.GetDenominatorShifting());

        ASSERT_EQUAL(seventhIntegerConversion.GetNumeratorMantissa(), eighthConversionRational.GetNumeratorMantissa());

        ASSERT_EQUAL(seventhIntegerConversion.GetDenominatorMantissa(), eighthConversionRational.GetDenominatorMantissa());

        ASSERT_THREE_EQUAL(seventhIntegerConversion.GetNumeratorShifting(), eighthConversionRational.GetNumeratorShifting(), 0);
    }
}

void Mathematics::ConversionRationalTesting::IntegerTest()
{
    const ConversionRational<int> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorMantissa(), 20);
    ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(firstIntegerConversion.GetMaxShifting(), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetReducibilityShifting(), 0);

    const ConversionRational<int16_t> secondIntegerConversion(-120);

    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorMantissa(), 120);
    ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(secondIntegerConversion.GetMaxShifting(), Log2OfPowerOfTwo<uint32_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetReducibilityShifting(), 0);

    const ConversionRational<int64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorMantissa(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(thirdIntegerConversion.GetMaxShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetReducibilityShifting(), 0);
}

void Mathematics::ConversionRationalTesting::UnsignedIntegerTest()
{
    const ConversionRational<uint32_t> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetNumeratorMantissa(), 20);
    ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(firstIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(firstIntegerConversion.GetMaxShifting(), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetReducibilityShifting(), 0);

    const ConversionRational<uint8_t> secondIntegerConversion(120);

    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetNumeratorMantissa(), 120);
    ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(secondIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(secondIntegerConversion.GetMaxShifting(), Log2OfPowerOfTwo<uint8_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetReducibilityShifting(), 0);

    const ConversionRational<uint64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetNumeratorMantissa(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetDenominatorMantissa(), 1);
    ASSERT_EQUAL(thirdIntegerConversion.GetMaxShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetReducibilityShifting(), 0);
}
