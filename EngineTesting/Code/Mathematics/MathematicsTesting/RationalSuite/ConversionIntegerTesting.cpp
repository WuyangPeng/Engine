// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:56)

#include "ConversionIntegerTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/Log2OfPowerOfTwoDetail.h"
#include "Mathematics/Rational/ConversionIntegerDetail.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ConversionIntegerTesting) 

void Mathematics::ConversionIntegerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NumericalValueSymbolTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ExponentTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MantissaTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
}

void Mathematics::ConversionIntegerTesting
	::NumericalValueSymbolTest()
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
		ConversionInteger<float> firstIntegerConversion(firstValue);

		if (0.0 <= firstValue)
		{
			ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else
		{
			ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(),NumericalValueSymbol::Negative);
		}
		

		double secondValue = secondRandomDistribution(generator);
		ConversionInteger<double> secondIntegerConversion(secondValue);

		if (0.0 <= secondValue)
		{
			ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(),NumericalValueSymbol::Positive);
		}
		else
		{
			ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(),NumericalValueSymbol::Negative);
		}

		float thirdValue = thirdRandomDistribution(generator);
		ConversionInteger<float> thirdIntegerConversion(thirdValue);
				
		ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(),NumericalValueSymbol::Positive);		

		double fourthValue = fourthRandomDistribution(generator);
		ConversionInteger<double> fourthIntegerConversion(fourthValue);
		
		ASSERT_ENUM_EQUAL(fourthIntegerConversion.GetSymbol(),NumericalValueSymbol::Positive);
	}
}

void Mathematics::ConversionIntegerTesting
	::ExponentTest() 
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
		ConversionInteger<float> firstIntegerConversion(firstValue);

		int firstRealExponent = firstIntegerConversion.GetShifting();
		float secondValue = FloatMath::Pow(2, static_cast<float>(firstRealExponent));
		ConversionInteger<float> secondIntegerConversion(secondValue);

		ASSERT_EQUAL(firstIntegerConversion.GetShifting(),secondIntegerConversion.GetShifting());

		double thirdValue = secondRandomDistribution(generator);
		ConversionInteger<double> thirdIntegerConversion(thirdValue);

		int secondRealExponent = thirdIntegerConversion.GetShifting();
		double fourthValue = DoubleMath::Pow(2, static_cast<double>(secondRealExponent));
		ConversionInteger<double> fourthIntegerConversion(fourthValue);

		ASSERT_EQUAL(thirdIntegerConversion.GetShifting(),fourthIntegerConversion.GetShifting());

		float fifthValue = thirdRandomDistribution(generator);
		ConversionInteger<float> fifthIntegerConversion(fifthValue);
				 
		ASSERT_EQUAL(fifthIntegerConversion.GetShifting(),0);

		double seventhValue = fourthRandomDistribution(generator);
		ConversionInteger<double> seventhIntegerConversion(seventhValue);

		ASSERT_EQUAL(seventhIntegerConversion.GetShifting(), 0);	
	}
}

void Mathematics::ConversionIntegerTesting
	::MantissaTest() 
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
	uniform_real<double> secondRandomDistribution{ -1.0e300, 1.0e300 };
	uniform_real<float> thirdRandomDistribution(-1.0e-1f, 1.0e-1f);
	uniform_real<double> fourthRandomDistribution(-1.0e-1, 1.0e-1);
	uniform_int<> fifthRandomDistribution(0,38);
	uniform_int<> sixthRandomDistribution(0,308);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		float firstValue = firstRandomDistribution(generator);
		ConversionInteger<float> firstIntegerConversion(firstValue);

		int firstExponent = firstIntegerConversion.GetShifting();
		uint64_t firstMantissa = firstIntegerConversion.GetMantissa();
		NumericalValueSymbol firstSign = firstIntegerConversion.GetSymbol();

		float secondValue = static_cast<float>(firstMantissa) /	FloatMath::Pow(2.0f, static_cast<float>(IntegerTraits<float>::TraitsType::g_ExponentShifting)) * FloatMath::Pow(2.0f, static_cast<float>(firstExponent));

		if (firstSign == NumericalValueSymbol::Negative)
			secondValue = -secondValue;

		ConversionInteger<float> secondIntegerConversion(secondValue);

		ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(),secondIntegerConversion.GetSymbol());

		ASSERT_EQUAL(firstIntegerConversion.GetShifting(),secondIntegerConversion.GetShifting());

		ASSERT_EQUAL(firstIntegerConversion.GetMantissa(),secondIntegerConversion.GetMantissa());

		ASSERT_EQUAL(firstIntegerConversion.GetMantissaSize(),secondIntegerConversion.GetMantissaSize());		

		double thirdValue = secondRandomDistribution(generator);
		ConversionInteger<double> thirdIntegerConversion(thirdValue);

		int secondExponent = thirdIntegerConversion.GetShifting();
		uint64_t secondMantissa = thirdIntegerConversion.GetMantissa();
		NumericalValueSymbol secondSign = thirdIntegerConversion.GetSymbol();

		double fourthValue = static_cast<double>(secondMantissa) / DoubleMath::Pow(2.0, static_cast<double>(IntegerTraits<double>::TraitsType::g_ExponentShifting)) * DoubleMath::Pow(2.0, static_cast<double>(secondExponent));

		if (secondSign == NumericalValueSymbol::Negative)
			fourthValue = -fourthValue;

		ConversionInteger<double> fourthIntegerConversion(fourthValue);

		ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(),fourthIntegerConversion.GetSymbol());

		ASSERT_EQUAL(thirdIntegerConversion.GetShifting(),fourthIntegerConversion.GetShifting());

		ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(),fourthIntegerConversion.GetMantissa());

		float fifthValue = thirdRandomDistribution(generator);
		ConversionInteger<float> fifthIntegerConversion(fifthValue);

		firstExponent = fifthIntegerConversion.GetShifting();
		firstMantissa = fifthIntegerConversion.GetMantissa();
		firstSign = fifthIntegerConversion.GetSymbol();

		ASSERT_EQUAL(firstExponent, 0);
		ASSERT_EQUAL(firstMantissa, 0);
		ASSERT_ENUM_EQUAL(firstSign, NumericalValueSymbol::Positive);

		double seventhValue = fourthRandomDistribution(generator);
		ConversionInteger<double> seventhIntegerConversion(seventhValue);

		secondExponent = seventhIntegerConversion.GetShifting();
		secondMantissa = seventhIntegerConversion.GetMantissa();
		secondSign = seventhIntegerConversion.GetSymbol();

		ASSERT_EQUAL(secondExponent, 0);
		ASSERT_EQUAL(secondMantissa, 0);
		ASSERT_ENUM_EQUAL(secondSign, NumericalValueSymbol::Positive);
	}
}

void Mathematics::ConversionIntegerTesting
	::IntegerTest() 
{
	ConversionInteger<int> firstIntegerConversion(20);

	ASSERT_EQUAL(firstIntegerConversion.GetShifting(),Log2OfPowerOfTwo<int>(22).GetLog2());
	ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
	ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

	ConversionInteger<int16_t> secondIntegerConversion(-120);

	ASSERT_EQUAL(secondIntegerConversion.GetShifting(),Log2OfPowerOfTwo<int16_t>(120).GetLog2());
	ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
	ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Negative);

	ConversionInteger<int64_t> thirdIntegerConversion(0);

	ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
	ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
	ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}

void Mathematics::ConversionIntegerTesting
	::UnsignedIntegerTest() 
{
	ConversionInteger<uint32_t> firstIntegerConversion(20);

	ASSERT_EQUAL(static_cast<uint32_t>(firstIntegerConversion.GetShifting()),Log2OfPowerOfTwo<uint32_t>(22).GetLog2());
	ASSERT_EQUAL(firstIntegerConversion.GetMantissa(), 20);
	ASSERT_ENUM_EQUAL(firstIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

	ConversionInteger<uint8_t> secondIntegerConversion(120);

	ASSERT_EQUAL(static_cast<uint8_t>(secondIntegerConversion.GetShifting()),Log2OfPowerOfTwo<uint8_t>(120).GetLog2());
	ASSERT_EQUAL(secondIntegerConversion.GetMantissa(), 120);
	ASSERT_ENUM_EQUAL(secondIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);

	ConversionInteger<uint64_t> thirdIntegerConversion(0);

	ASSERT_EQUAL(thirdIntegerConversion.GetShifting(), 0);
	ASSERT_EQUAL(thirdIntegerConversion.GetMantissa(), 0);
	ASSERT_ENUM_EQUAL(thirdIntegerConversion.GetSymbol(), NumericalValueSymbol::Positive);
}


