// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 14:46)

#include "QuerySortToolsTesting.h"
#include "Mathematics/Query/QuerySortTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuerySortToolsTesting) 

void Mathematics::QuerySortToolsTesting
	::MainTest()
{
	 ASSERT_NOT_THROW_EXCEPTION_0(SortTwoValueTest);
	 ASSERT_NOT_THROW_EXCEPTION_0(SortThreeValueTest);
	 ASSERT_NOT_THROW_EXCEPTION_0(SortFourValueTest);
}

void Mathematics::QuerySortToolsTesting
	::SortTwoValueTest()
{
	default_random_engine generator;
	uniform_int<> firstRandomDistribution(0, 2000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		int firstValue = firstRandomDistribution(generator);
		int secondValue = firstRandomDistribution(generator);

		QuerySortTools querySortTools(firstValue, secondValue);

		ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));

		if (firstValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else 
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
	}
}

void Mathematics::QuerySortToolsTesting
	::SortThreeValueTest()
{
	default_random_engine generator;
	uniform_int<> firstRandomDistribution(0, 2000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		int firstValue = firstRandomDistribution(generator);
		int secondValue = firstRandomDistribution(generator);
		int thirdValue = firstRandomDistribution(generator);

		QuerySortTools querySortTools(firstValue, secondValue, thirdValue);
	
		ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));
		ASSERT_TRUE(querySortTools.GetValue(1) <= querySortTools.GetValue(2));

		if (firstValue <= secondValue && secondValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (firstValue <= thirdValue && thirdValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (secondValue <= firstValue && firstValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (secondValue <= thirdValue && thirdValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (thirdValue <= firstValue && firstValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (thirdValue <= secondValue && secondValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
	}
}

void Mathematics::QuerySortToolsTesting
	::SortFourValueTest()
{
	default_random_engine generator;
	uniform_int<> firstRandomDistribution(0, 2000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		int firstValue = firstRandomDistribution(generator);
		int secondValue = firstRandomDistribution(generator);
		int thirdValue = firstRandomDistribution(generator);
		int fourthValue = firstRandomDistribution(generator);

		QuerySortTools querySortTools(firstValue, secondValue, thirdValue, fourthValue);

		ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));
		ASSERT_TRUE(querySortTools.GetValue(1) <= querySortTools.GetValue(2));
		ASSERT_TRUE(querySortTools.GetValue(2) <= querySortTools.GetValue(3)); 

		if (firstValue <= secondValue && secondValue <= thirdValue && thirdValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (firstValue <= secondValue && secondValue <= fourthValue && fourthValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (firstValue <= thirdValue && thirdValue <= secondValue && secondValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (firstValue <= thirdValue && thirdValue <= fourthValue && fourthValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (secondValue <= firstValue && firstValue <= thirdValue && thirdValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (secondValue <= firstValue && firstValue <= fourthValue && fourthValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (secondValue <= thirdValue && thirdValue <= firstValue && firstValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (secondValue <= thirdValue && thirdValue <= fourthValue && fourthValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (thirdValue <= firstValue && firstValue <= secondValue && secondValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (thirdValue <= firstValue && firstValue <= fourthValue && fourthValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (thirdValue <= secondValue && secondValue <= firstValue && firstValue <= fourthValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (thirdValue <= secondValue && secondValue <= fourthValue && fourthValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (thirdValue <= fourthValue && fourthValue <= firstValue && firstValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (thirdValue <= fourthValue && fourthValue <= secondValue && secondValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (fourthValue <= firstValue && firstValue <= secondValue && secondValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (fourthValue <= firstValue && firstValue <= thirdValue && thirdValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (fourthValue <= secondValue && secondValue <= firstValue && firstValue <= thirdValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
		else if (fourthValue <= secondValue && secondValue <= thirdValue && thirdValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (fourthValue <= thirdValue && thirdValue <= firstValue && firstValue <= secondValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
		}
		else if (fourthValue <= thirdValue && thirdValue <= secondValue && secondValue <= firstValue)
		{
			ASSERT_ENUM_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
		}
	}
}

