// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:11)

#include "FrameMemorySystemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FrameMemorySystemTesting)

void CoreTools::FrameMemorySystemTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
}

void CoreTools::FrameMemorySystemTesting ::SucceedTest() noexcept
{
	 
}

void CoreTools::FrameMemorySystemTesting ::ExceptionTest() noexcept
{
	 
}