// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:29)

#include "TwoBitArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 



UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TwoBitArrayTesting)

void CoreTools::TwoBitArrayTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstBitArrayTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NonConstBitArrayTest);
}

void CoreTools::TwoBitArrayTesting ::ConstBitArrayTest() noexcept
{
	 
}

void CoreTools::TwoBitArrayTesting ::NonConstBitArrayTest() noexcept
{
	 
}