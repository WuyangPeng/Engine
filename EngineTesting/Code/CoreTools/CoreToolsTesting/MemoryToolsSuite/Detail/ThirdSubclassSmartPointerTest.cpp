// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 10:40)

#include "ThirdSubclassSmartPointerTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ThirdSubclassSmartPointerTest
	::ThirdSubclassSmartPointerTest(int value) noexcept
	:ParentType{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThirdSubclassSmartPointerTest)

