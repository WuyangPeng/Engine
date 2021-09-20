// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:18)

#include "HeapAllocateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, HeapAllocateTesting)

void CoreTools::HeapAllocateTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CharTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DoubleTest);
}

void CoreTools::HeapAllocateTesting
	::CharTest()
{
	constexpr auto size = 10;

	HeapAllocate<char> heap{ size };

	ASSERT_EQUAL(heap.GetLength(), size);
	ASSERT_EQUAL(heap.GetByteLength(), size * boost::numeric_cast<int>(sizeof(char)));
	ASSERT_UNEQUAL_NULL_PTR(heap.GetPoint());
}

void CoreTools::HeapAllocateTesting
	::DoubleTest()
{
	constexpr auto size = 20;

	const HeapAllocate<double> heap{ size };

	ASSERT_EQUAL(heap.GetLength(), size);
	ASSERT_EQUAL(heap.GetByteLength(), size * boost::numeric_cast<int>(sizeof(double)));
	ASSERT_UNEQUAL_NULL_PTR(heap.GetPoint());
}

