// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:59)

#include "FastNegativeExpTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/FastNegativeExpDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  

using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class FastNegativeExp<float>;
	template class FastNegativeExp<double>;
}
#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,FastNegativeExpTesting) 

void Mathematics::FastNegativeExpTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FloatFastExpBoundaryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DoubleFastExpBoundaryTest);
}

void Mathematics::FastNegativeExpTesting
	::FloatFastExpTest()
{
	// ÀÊª˙÷µ≤‚ ‘
	default_random_engine randomEngine{};
	uniform_real<float> randomDistribution{ FloatMath::GetValue(0),FloatMath::GetExponent() }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		float value = randomDistribution(randomEngine);

		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpMoreRoughCalculation(value),  exp(-value),1.0e-3f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpRoughCalculation(value), exp(-value),1.0e-4f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpPreciseCalculation(value), exp(-value),1.0e-5f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpMorePreciseCalculation(value), exp(-value),1.0e-6f);
	}
}

void Mathematics::FastNegativeExpTesting
	::DoubleFastExpTest()
{
	// ÀÊª˙÷µ≤‚ ‘
	default_random_engine randomEngine{};
	uniform_real<double> randomDistribution{ DoubleMath::GetValue(0),DoubleMath::GetExponent() }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		auto value = randomDistribution(randomEngine);

		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpMoreRoughCalculation(value), exp(-value),1.0e-3);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpRoughCalculation(value), exp(-value),1.0e-4);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpPreciseCalculation(value), exp(-value),1.0e-5);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpMorePreciseCalculation(value), exp(-value),1.0e-6);
	}
}

void Mathematics::FastNegativeExpTesting
	::FloatFastExpBoundaryTest()
{
	// ÀÊª˙÷µ≤‚ ‘
	default_random_engine randomEngine{};
	uniform_real<float> randomDistribution{ FloatMath::GetExponent(),FloatMath::sm_MaxReal };
 
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		auto value = randomDistribution(randomEngine);

		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpMoreRoughCalculation(value),  exp(-value),1.0e-8f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpRoughCalculation(value), exp(-value),1.0e-8f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpPreciseCalculation(value), exp(-value),1.0e-8f);
		ASSERT_APPROXIMATE(FloatFastNegativeExp::FastNegativeExpMorePreciseCalculation(value), exp(-value),1.0e-8f);
	}	
}

void Mathematics::FastNegativeExpTesting
	::DoubleFastExpBoundaryTest()
{
	// ÀÊª˙÷µ≤‚ ‘
	default_random_engine randomEngine{};
	uniform_real<double> randomDistribution{ DoubleMath::GetExponent(),DoubleMath::sm_MaxReal };  

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		auto value = randomDistribution(randomEngine);

		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpMoreRoughCalculation(value),exp(-value),1.0e-10);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpRoughCalculation(value),exp(-value),1.0e-10);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpPreciseCalculation(value),exp(-value),1.0e-10);
		ASSERT_APPROXIMATE(DoubleFastNegativeExp::FastNegativeExpMorePreciseCalculation(value),exp(-value),1.0e-10);
	}
}
