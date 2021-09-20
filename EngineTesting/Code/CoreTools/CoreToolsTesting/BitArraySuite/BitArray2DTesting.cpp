// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:23)

#include "BitArray2DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BitArray2DTesting)

void CoreTools::BitArray2DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstBitArray2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NonConstBitArray2DTest);
}

void CoreTools::BitArray2DTesting
	::ConstBitArray2DTest() noexcept
{
	 
}

void CoreTools::BitArray2DTesting ::NonConstBitArray2DTest() noexcept
{
	 
}