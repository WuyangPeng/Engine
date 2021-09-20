// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 19:02)

#include "MinHeapRecordIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/DataTypes/MinHeapRecordIndex.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MinHeapRecordIndexTesting)

void CoreTools::MinHeapRecordIndexTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(IndexTest);
}

void CoreTools::MinHeapRecordIndexTesting
	::IndexTest()
{
	constexpr auto recordIndexSize = 11;

	MinHeapRecordIndex firstMinHeapRecordIndex{ recordIndexSize };

	ASSERT_EQUAL(firstMinHeapRecordIndex.GetMaxElements(), recordIndexSize);

	for (auto index = 0; index < recordIndexSize; ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordIndex.GetHeapIndex(index), index);
	}

	for (auto index = 0; index < recordIndexSize / 2; ++index)
	{
		firstMinHeapRecordIndex.ChangeIndex(index, recordIndexSize - index - 1);
	}

	MinHeapRecordIndex secondMinHeapRecordIndex{ firstMinHeapRecordIndex };

	ASSERT_EQUAL(secondMinHeapRecordIndex.GetMaxElements(), recordIndexSize);

	for (auto index = 0; index < firstMinHeapRecordIndex.GetMaxElements(); ++index)
	{
		ASSERT_EQUAL(firstMinHeapRecordIndex.GetHeapIndex(index), firstMinHeapRecordIndex.GetMaxElements() - index - 1);
	}

	MinHeapRecordIndex thirdMinHeapRecordIndex{ recordIndexSize + 2, secondMinHeapRecordIndex };

	ASSERT_EQUAL(thirdMinHeapRecordIndex.GetMaxElements(), recordIndexSize + 2);

	for (int index = 0; index < secondMinHeapRecordIndex.GetMaxElements(); ++index)
	{
		ASSERT_EQUAL(thirdMinHeapRecordIndex.GetHeapIndex(index), secondMinHeapRecordIndex.GetMaxElements() - index - 1);
	}

	for (auto index = secondMinHeapRecordIndex.GetMaxElements(); index < thirdMinHeapRecordIndex.GetMaxElements(); ++index)
	{
		ASSERT_EQUAL(thirdMinHeapRecordIndex.GetHeapIndex(index), index);
	}
}


