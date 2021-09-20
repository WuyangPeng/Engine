// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 17:16)

#include "ResourceHandleTesting.h"
#include "Detail/ResourceHandleTestTag.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ResourceHandleTesting)

void CoreTools::ResourceHandleTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ResourceHandleTest);
}

void CoreTools::ResourceHandleTesting ::ResourceHandleTest() noexcept
{
	 
}