// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.1.0.1 (2020/04/06 23:13)

#include "MathematicsFor3DCodeTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
 
namespace BookGeometry
{
	 
}

BookGeometry::MathematicsFor3DCodeTesting
	::MathematicsFor3DCodeTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	 
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, MathematicsFor3DCodeTesting)

void BookGeometry::MathematicsFor3DCodeTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::MathematicsFor3DCodeTesting
	::MainTest() 
{
	 
}

