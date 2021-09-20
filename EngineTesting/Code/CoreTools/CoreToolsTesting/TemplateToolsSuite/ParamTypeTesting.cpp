// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 16:05)

#include "ParamTypeTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ParamTypeTesting)

void CoreTools::ParamTypeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ParamTypeTest, 0, "");
}

void CoreTools::ParamTypeTesting ::ParamTypeTest([[maybe_unused]] ParamType<int>::type integer, [[maybe_unused]] ParamType<string>::type characterString) noexcept
{
 
}


