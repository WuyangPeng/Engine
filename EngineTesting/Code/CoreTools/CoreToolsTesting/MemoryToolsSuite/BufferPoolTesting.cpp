// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 10:40)

#include "BufferPoolTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
 

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferPoolTesting)

void CoreTools::BufferPoolTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PoolTest);
}

void CoreTools::BufferPoolTesting ::PoolTest() noexcept
{
	 
}