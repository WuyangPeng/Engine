// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 19:03)

#include "MinHeapRecordStoredTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/DataTypes/MinHeapRecordStoredDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MinHeapRecordStoredTesting)

void CoreTools::MinHeapRecordStoredTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
}

void CoreTools::MinHeapRecordStoredTesting
	::FloatTest()
{
	constexpr auto arraySize = 5;

	MinHeapRecordStored<int, float> firstMinHeapRecordArray{ arraySize,0.0f };

	ASSERT_EQUAL(firstMinHeapRecordArray.GetMaxElements(), arraySize);

	for (auto index = 0; index < arraySize; ++index)
	{
		firstMinHeapRecordArray.SetGenerator(index, arraySize - index);
		firstMinHeapRecordArray.SetValue(index, index * 2.0f);
	}

	MinHeapRecordStored<int, float> secondMinHeapRecordArray{ firstMinHeapRecordArray };

	ASSERT_EQUAL(secondMinHeapRecordArray.GetMaxElements(), arraySize);

	for (auto index = 0; index < arraySize; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordArray.GetGenerator(index), arraySize - index);
		ASSERT_APPROXIMATE(firstMinHeapRecordArray.GetValue(index), index * 2.0f, 1.0e-8f);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetUniqueIndex(index), index);
		ASSERT_EQUAL(secondMinHeapRecordArray.GetGenerator(index), arraySize - index);
		ASSERT_APPROXIMATE(secondMinHeapRecordArray.GetValue(index), index * 2.0f, 1.0e-8f);
		ASSERT_EQUAL(secondMinHeapRecordArray.GetUniqueIndex(index), index);
	}

	MinHeapRecordStored<int, float> thirdMinHeapRecordArray{ arraySize + 1,0.0f };

	ASSERT_EQUAL(thirdMinHeapRecordArray.GetMaxElements(), arraySize + 1);

	for (auto index = 0; index < arraySize + 1; ++index)
	{
		thirdMinHeapRecordArray.SetGenerator(index, arraySize - index + 2);
		thirdMinHeapRecordArray.SetValue(index, index * 3.0f);
	}

	firstMinHeapRecordArray = thirdMinHeapRecordArray;

	ASSERT_EQUAL(firstMinHeapRecordArray.GetMaxElements(), arraySize + 1);

	for (auto index = 0; index < arraySize + 1; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordArray.GetGenerator(index), arraySize - index + 2);
		ASSERT_APPROXIMATE(firstMinHeapRecordArray.GetValue(index), index * 3.0f, 1.0e-8f);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetUniqueIndex(index), index);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetGenerator(index), arraySize - index + 2);
		ASSERT_APPROXIMATE(thirdMinHeapRecordArray.GetValue(index), index * 3.0f, 1.0e-8f);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetUniqueIndex(index), index);
	}
}

void CoreTools::MinHeapRecordStoredTesting
	::IntegerTest()
{
	constexpr auto arraySize = 6;

	MinHeapRecordStored<int, int> firstMinHeapRecordArray{ arraySize,0 };

	ASSERT_EQUAL(firstMinHeapRecordArray.GetMaxElements(), arraySize);

	for (auto index = 0; index < arraySize; ++index)
	{
		firstMinHeapRecordArray.SetGenerator(index, arraySize - index);
		firstMinHeapRecordArray.SetValue(index, index * 2);
	}

	MinHeapRecordStored<int, int> secondMinHeapRecordArray{ firstMinHeapRecordArray };

	ASSERT_EQUAL(secondMinHeapRecordArray.GetMaxElements(), arraySize);

	for (auto index = 0; index < arraySize; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordArray.GetGenerator(index), arraySize - index);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetValue(index), index * 2);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetUniqueIndex(index), index);
		ASSERT_EQUAL(secondMinHeapRecordArray.GetGenerator(index), arraySize - index);
		ASSERT_EQUAL(secondMinHeapRecordArray.GetValue(index), index * 2);
		ASSERT_EQUAL(secondMinHeapRecordArray.GetUniqueIndex(index), index);
	}

	MinHeapRecordStored<int, int> thirdMinHeapRecordArray{ arraySize + 1,secondMinHeapRecordArray };

	for (auto index = 0; index < arraySize; ++index)
	{
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetGenerator(index), arraySize - index);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetValue(index), index * 2);
	}

	ASSERT_EQUAL(thirdMinHeapRecordArray.GetValue(arraySize), 0);

	ASSERT_EQUAL(thirdMinHeapRecordArray.GetMaxElements(), arraySize + 1);

	for (auto index = 0; index < arraySize + 1; ++index)
	{
		thirdMinHeapRecordArray.SetGenerator(index, arraySize - index + 2);
		thirdMinHeapRecordArray.SetValue(index, index * 3);
	}

	firstMinHeapRecordArray = thirdMinHeapRecordArray;

	ASSERT_EQUAL(firstMinHeapRecordArray.GetMaxElements(), arraySize + 1);

	for (auto index = 0; index < arraySize + 1; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordArray.GetGenerator(index), arraySize - index + 2);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetValue(index), index * 3);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetUniqueIndex(index), index);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetGenerator(index), arraySize - index + 2);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetValue(index), index * 3);
		ASSERT_EQUAL(thirdMinHeapRecordArray.GetUniqueIndex(index), index);
	}

	for (auto index = 0; index < arraySize / 2 + 1; ++index)
	{
		firstMinHeapRecordArray.ChangeValue(index, arraySize - index);
	}

	for (auto index = 0; index < arraySize + 1; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordArray.GetGenerator(arraySize - index), arraySize - index + 2);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetValue(arraySize - index), index * 3);
		ASSERT_EQUAL(firstMinHeapRecordArray.GetUniqueIndex(arraySize - index), index);
	}
}

