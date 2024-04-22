///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:29)

#include "ConversionIntegerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Log2OfPowerOfTwoDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/ConversionIntegerDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"

#include <random>

Mathematics::ConversionIntegerTesting::ConversionIntegerTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ConversionIntegerTesting)

void Mathematics::ConversionIntegerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ConversionIntegerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
}

void Mathematics::ConversionIntegerTesting::NumericalValueSymbolTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real<float> thirdRandomDistribution{ -1.0e-1f, 1.0e-1f };
    std::uniform_real<double> fourthRandomDistribution{ -1.0e-1, 1.0e-1 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto secondValue = randomDistribution1(generator);
        const ConversionInteger<double> secondIntegerConversion(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto thirdValue = thirdRandomDistribution(generator);
        const ConversionInteger<float> thirdIntegerConversion(thirdValue);

        ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

        auto fourthValue = fourthRandomDistribution(generator);
        const ConversionInteger<double> fourthIntegerConversion(fourthValue);

        ASSERT_EQUAL(fourthIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    }
}

void Mathematics::ConversionIntegerTesting::ExponentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real<float> thirdRandomDistribution{ -1.0e-1f, 1.0e-1f };
    std::uniform_real<double> fourthRandomDistribution{ -1.0e-1, 1.0e-1 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        const auto firstRealExponent = firstIntegerConversion.GetShifting();
        auto secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        const ConversionInteger<float> secondIntegerConversion(secondValue);

        ASSERT_EQUAL(firstIntegerConversion.GetShifting(), secondIntegerConversion.GetShifting());

        auto thirdValue = randomDistribution1(generator);
        const ConversionInteger<double> thirdIntegerConversion(thirdValue);

        const auto secondRealExponent = thirdIntegerConversion.GetShifting();
        auto fourthValue = MathD::Pow(2, static_cast<double>(secondRealExponent));
        const ConversionInteger<double> fourthIntegerConversion(fourthValue);

        ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), fourthIntegerConversion.GetShifting());

        auto fifthValue = thirdRandomDistribution(generator);
        const ConversionInteger<float> fifthIntegerConversion(fifthValue);

        ASSERT_EQUAL(fifthIntegerConversion.GetShifting(), 0);

        auto seventhValue = fourthRandomDistribution(generator);
        const ConversionInteger<double> seventhIntegerConversion(seventhValue);

        ASSERT_EQUAL(seventhIntegerConversion.GetShifting(), 0);
    }
}

void Mathematics::ConversionIntegerTesting::MantissaTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real<double> randomDistribution1{ -1.0e300, 1.0e300 };
    std::uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    std::uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);
    const std::uniform_int<> fifthRandomDistribution(0, 38);
    const std::uniform_int<> sixthRandomDistribution(0, 308);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        auto firstExponent = firstIntegerConversion.GetShifting();
        auto firstMantissa = firstIntegerConversion.GetMantissa();
        auto firstSign = firstIntegerConversion.GetSymbol();

        auto secondValue = static_cast<float>(firstMantissa) / MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) * MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        const ConversionInteger<float> secondIntegerConversion(secondValue);

        ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), secondIntegerConversion.GetSymbol());

        ASSERT_EQUAL(firstIntegerConversion.GetShifting(), secondIntegerConversion.GetShifting());

        ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), secondIntegerConversion.GetMantissa());

        ASSERT_EQUAL(firstIntegerConversion.GetMantissaSize(), secondIntegerConversion.GetMantissaSize());

        auto thirdValue = randomDistribution1(generator);
        const ConversionInteger<double> thirdIntegerConversion(thirdValue);

        auto secondExponent = thirdIntegerConversion.GetShifting();
        auto secondMantissa = thirdIntegerConversion.GetMantissa();
        auto secondSign = thirdIntegerConversion.GetSymbol();

        auto fourthValue = static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) * MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        const ConversionInteger<double> fourthIntegerConversion(fourthValue);

        ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), fourthIntegerConversion.GetSymbol());

        ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), fourthIntegerConversion.GetShifting());

        ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), fourthIntegerConversion.GetMantissa());

        auto fifthValue = thirdRandomDistribution(generator);
        const ConversionInteger<float> fifthIntegerConversion(fifthValue);

        firstExponent = fifthIntegerConversion.GetShifting();
        firstMantissa = fifthIntegerConversion.GetMantissa();
        firstSign = fifthIntegerConversion.GetSymbol();

        ASSERT_EQUAL(firstExponent, 0);
        ASSERT_EQUAL(firstMantissa, 0);
        ASSERT_EQUAL(firstSign, NumericalValueSymbol::Positive);

        auto seventhValue = fourthRandomDistribution(generator);
        const ConversionInteger<double> seventhIntegerConversion(seventhValue);

        secondExponent = seventhIntegerConversion.GetShifting();
        secondMantissa = seventhIntegerConversion.GetMantissa();
        secondSign = seventhIntegerConversion.GetSymbol();

        ASSERT_EQUAL(secondExponent, 0);
        ASSERT_EQUAL(secondMantissa, 0);
        ASSERT_EQUAL(secondSign, NumericalValueSymbol::Positive);
    }
}

void Mathematics::ConversionIntegerTesting::IntegerTest()
{
    const ConversionInteger<int> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetShifting(), Log2OfPowerOfTwo<int>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
    ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<int16_t> secondIntegerConversion(-120);

    ASSERT_EQUAL(secondIntegerConversion.GetShifting(), Log2OfPowerOfTwo<int16_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
    ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);

    const ConversionInteger<int64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}

void Mathematics::ConversionIntegerTesting::UnsignedIntegerTest()
{
    const ConversionInteger<uint32_t> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetShifting(), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
    ASSERT_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<uint8_t> secondIntegerConversion(120);

    ASSERT_EQUAL(secondIntegerConversion.GetShifting(), Log2OfPowerOfTwo<uint8_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
    ASSERT_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<uint64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}
