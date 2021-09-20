// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/26 16:25)

#include "IntegerMultiplicationTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerMultiplicationDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include <boost/utility/binary.hpp> 
 
using std::vector;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class IntegerData<21>;
	template class IntegerData<22>;
	template class IntegerData<29>;
	template class IntegerData<32>;

	template class IntegerMultiplication<21>;
	template class IntegerMultiplication<22>;
	template class IntegerMultiplication<29>;
	template class IntegerMultiplication<32>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerMultiplicationTesting) 

void Mathematics::IntegerMultiplicationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MultiplicationTest);	
}

void Mathematics::IntegerMultiplicationTesting
	::MultiplicationTest()
{
	default_random_engine generator{};
	uniform_int<> firstRandomDistribution(0, UINT16_MAX);
	uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vector<uint16_t> firstShortVector(40);
		vector<uint16_t> secondShortVector(40);

		// ±‹√‚º∆À„“Á≥ˆ
		for(int i = 0;i < 19;++i)
		{
			firstShortVector[i] = secondRandomDistribution(generator);
			secondShortVector[i] = secondRandomDistribution(generator);			
		}

		IntegerData<20> firstInteger(firstShortVector);
		IntegerData<20> secondInteger(secondShortVector);
		
		IntegerMultiplication<20> thirdIntegerDataOperator(firstInteger,secondInteger);
		IntegerData<20> thirdInteger = thirdIntegerDataOperator.GetMultiplication();

		IntegerMultiplication<20> fourthIntegerDataOperator(secondInteger,firstInteger);
		IntegerData<20> fourthInteger = fourthIntegerDataOperator.GetMultiplication();		

		ASSERT_EQUAL(thirdInteger,fourthInteger);

		uint64_t firstValue = firstRandomDistribution(generator);
		uint64_t secondValue = firstRandomDistribution(generator);

		IntegerData<4> fifthInteger(firstValue);
		IntegerData<4> sixthInteger(secondValue);

		IntegerMultiplication<4> fifthIntegerDataOperator(fifthInteger,sixthInteger);

		ASSERT_EQUAL(fifthIntegerDataOperator.GetMultiplication(),IntegerData<4>(firstValue * secondValue));		
	}	
}
