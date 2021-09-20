// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:27)

#include "BitArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BitArrayTesting)

void CoreTools::BitArrayTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstBitArrayTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NonConstBitArrayTest);
}

void CoreTools::BitArrayTesting
	::ConstBitArrayTest() noexcept
{
	 
}

void CoreTools::BitArrayTesting ::NonConstBitArrayTest() noexcept
{
	 
}