///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 11:30)

#include "ConversionIntegerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Log2OfPowerOfTwoDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/ConversionIntegerDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;


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
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    const uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    const uniform_real<float> thirdRandomDistribution{ -1.0e-1f, 1.0e-1f };
    const uniform_real<double> fourthRandomDistribution{ -1.0e-1, 1.0e-1 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        if (0.0 <= firstValue)
        {
            ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto secondValue = secondRandomDistribution(generator);
        const ConversionInteger<double> secondIntegerConversion(secondValue);

        if (0.0 <= secondValue)
        {
            ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);
        }

        auto thirdValue = thirdRandomDistribution(generator);
        const ConversionInteger<float> thirdIntegerConversion(thirdValue);

        ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

        auto fourthValue = fourthRandomDistribution(generator);
        const ConversionInteger<double> fourthIntegerConversion(fourthValue);

        ASSERT_ENUM_EQUAL(fourthIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
    }
}

void Mathematics::ConversionIntegerTesting::ExponentTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    const uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    const uniform_real<float> thirdRandomDistribution{ -1.0e-1f, 1.0e-1f };
    const uniform_real<double> fourthRandomDistribution{ -1.0e-1, 1.0e-1 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        const auto firstRealExponent = firstIntegerConversion.GetShifting();
        auto secondValue = MathF::Pow(2, static_cast<float>(firstRealExponent));
        const ConversionInteger<float> secondIntegerConversion(secondValue);

        ASSERT_EQUAL(firstIntegerConversion.GetShifting(), secondIntegerConversion.GetShifting());

        auto thirdValue = secondRandomDistribution(generator);
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
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    const uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
    const uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
    const uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);
    const uniform_int<> fifthRandomDistribution(0, 38);
    const uniform_int<> sixthRandomDistribution(0, 308);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);
        const ConversionInteger<float> firstIntegerConversion(firstValue);

        auto firstExponent = firstIntegerConversion.GetShifting();
        auto firstMantissa = firstIntegerConversion.GetMantissa();
        auto firstSign = firstIntegerConversion.GetSymbol();

        auto secondValue = static_cast<float>(firstMantissa) / MathF::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::exponentShifting)) * MathF::Pow(2.0f, static_cast<float>(firstExponent));

        if (firstSign == NumericalValueSymbol::Negative)
            secondValue = -secondValue;

        const ConversionInteger<float> secondIntegerConversion(secondValue);

        ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), secondIntegerConversion.GetSymbol());

        ASSERT_EQUAL(firstIntegerConversion.GetShifting(), secondIntegerConversion.GetShifting());

        ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), secondIntegerConversion.GetMantissa());

        ASSERT_EQUAL(firstIntegerConversion.GetMantissaSize(), secondIntegerConversion.GetMantissaSize());

        auto thirdValue = secondRandomDistribution(generator);
        const ConversionInteger<double> thirdIntegerConversion(thirdValue);

        auto secondExponent = thirdIntegerConversion.GetShifting();
        auto secondMantissa = thirdIntegerConversion.GetMantissa();
        auto secondSign = thirdIntegerConversion.GetSymbol();

        auto fourthValue = static_cast<double>(secondMantissa) / MathD::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::exponentShifting)) * MathD::Pow(2.0, static_cast<double>(secondExponent));

        if (secondSign == NumericalValueSymbol::Negative)
            fourthValue = -fourthValue;

        const ConversionInteger<double> fourthIntegerConversion(fourthValue);

        ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), fourthIntegerConversion.GetSymbol());

        ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), fourthIntegerConversion.GetShifting());

        ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), fourthIntegerConversion.GetMantissa());

        auto fifthValue = thirdRandomDistribution(generator);
        const ConversionInteger<float> fifthIntegerConversion(fifthValue);

        firstExponent = fifthIntegerConversion.GetShifting();
        firstMantissa = fifthIntegerConversion.GetMantissa();
        firstSign = fifthIntegerConversion.GetSymbol();

        ASSERT_EQUAL(firstExponent, 0);
        ASSERT_EQUAL(firstMantissa, 0);
        ASSERT_ENUM_EQUAL(firstSign, NumericalValueSymbol::Positive);

        auto seventhValue = fourthRandomDistribution(generator);
        const ConversionInteger<double> seventhIntegerConversion(seventhValue);

        secondExponent = seventhIntegerConversion.GetShifting();
        secondMantissa = seventhIntegerConversion.GetMantissa();
        secondSign = seventhIntegerConversion.GetSymbol();

        ASSERT_EQUAL(secondExponent, 0);
        ASSERT_EQUAL(secondMantissa, 0);
        ASSERT_ENUM_EQUAL(secondSign, NumericalValueSymbol::Positive);
    }
}

void Mathematics::ConversionIntegerTesting::IntegerTest()
{
    const ConversionInteger<int> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetShifting(), Log2OfPowerOfTwo<int>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
    ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<int16_t> secondIntegerConversion(-120);

    ASSERT_EQUAL(secondIntegerConversion.GetShifting(), Log2OfPowerOfTwo<int16_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
    ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);

    const ConversionInteger<int64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
    ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}

void Mathematics::ConversionIntegerTesting::UnsignedIntegerTest()
{
    const ConversionInteger<uint32_t> firstIntegerConversion(20);

    ASSERT_EQUAL(firstIntegerConversion.GetShifting(), Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
    ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
    ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<uint8_t> secondIntegerConversion(120);

    ASSERT_EQUAL(secondIntegerConversion.GetShifting(), Log2OfPowerOfTwo<uint8_t>(120).GetLog2());
    ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
    ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

    const ConversionInteger<uint64_t> thirdIntegerConversion(0);

    ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
    ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
    ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}
