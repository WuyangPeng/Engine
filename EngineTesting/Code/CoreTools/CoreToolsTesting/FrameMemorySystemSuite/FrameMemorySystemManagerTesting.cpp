// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 18:10)

#include "FrameMemorySystemManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FrameMemorySystemManagerTesting)

void CoreTools::FrameMemorySystemManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FrameMemorySystemManagerTest);
}

void CoreTools::FrameMemorySystemManagerTesting
	::FrameMemorySystemManagerTest() noexcept
{
	 
}

