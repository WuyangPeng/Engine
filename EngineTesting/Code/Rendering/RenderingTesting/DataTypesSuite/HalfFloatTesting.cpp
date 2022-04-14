// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/03 15:23)

#include "HalfFloatTesting.h"
#include "Rendering/DataTypes/HalfFloat.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,HalfFloatTesting) 

void Rendering::HalfFloatTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BigFloatTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SmallFloatTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UInt16Test);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}
 
void Rendering::HalfFloatTesting
	::BigFloatTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> floatRandomDistribution(-32768.0f,32768.0f); // 2的15次方
	
	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		float firstValue = floatRandomDistribution(generator);

	    HalfFloat firstHalfFloat(firstValue);

		float secondValue = firstHalfFloat.ToFloat();

		// 精度只有1/2^10
		ASSERT_APPROXIMATE(firstValue,secondValue,Mathematics::MathF::FAbs(firstValue / 1024.0f));

		HalfFloat secondHalfFloat(secondValue);

		float thirdValue = firstHalfFloat.ToFloat();

		ASSERT_APPROXIMATE(thirdValue,secondValue,1e-8f);

		ASSERT_EQUAL(firstHalfFloat,secondHalfFloat);
		ASSERT_TRUE(Approximate(firstHalfFloat,secondHalfFloat,1e-8f));
	}
}

void Rendering::HalfFloatTesting
	::SmallFloatTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-1.0f / 32768.0f,1.0f / 32768.0f); // 2的-15次方

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		float firstValue = firstFloatRandomDistribution(generator);

		HalfFloat firstHalfFloat(firstValue);

		float secondValue = firstHalfFloat.ToFloat();

		// 精度只有1/2^10
		ASSERT_APPROXIMATE(firstValue,secondValue,Mathematics::MathF::FAbs(firstValue * 1024.0f));

		HalfFloat secondHalfFloat(secondValue);

		float thirdValue = firstHalfFloat.ToFloat();

		ASSERT_APPROXIMATE(thirdValue,secondValue,1e-8f);

		ASSERT_EQUAL(firstHalfFloat,secondHalfFloat);
		ASSERT_TRUE(Approximate(firstHalfFloat,secondHalfFloat,1e-8f));
	}
}

void Rendering::HalfFloatTesting
	::UInt16Test()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<HalfFloat::HalfFloatType> integerRandomDistribution(0,65535);
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		HalfFloat::HalfFloatType firstValue = integerRandomDistribution(generator);
// 
// 		HalfFloat firstHalfFloat;
// 		firstHalfFloat.FromHalfFloatType(firstValue);
// 
// 		HalfFloat::HalfFloatType secondValue = firstHalfFloat.ToHalfFloat();
// 
// 		ASSERT_EQUAL(firstValue,secondValue);
// 
// 		HalfFloat secondHalfFloat;
// 		secondHalfFloat.FromHalfFloatType(secondValue);
// 
// 		HalfFloat::HalfFloatType thirdValue = secondHalfFloat.ToHalfFloat();
// 
// 		ASSERT_EQUAL(thirdValue,secondValue);
// 
// 		ASSERT_EQUAL(firstHalfFloat,secondHalfFloat);
// 		ASSERT_TRUE(Approximate(firstHalfFloat,secondHalfFloat,1e-8f));
// 	}
}

void Rendering::HalfFloatTesting
	::OperatorTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> floatRandomDistribution(-32768.0f,32768.0f); // 2的15次方

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		float firstValue = floatRandomDistribution(generator);

		HalfFloat firstHalfFloat(firstValue);

		HalfFloat secondHalfFloat = -firstHalfFloat;

		ASSERT_APPROXIMATE(firstHalfFloat.ToFloat(),-secondHalfFloat.ToFloat(),1e-8f); 
	}
}

 