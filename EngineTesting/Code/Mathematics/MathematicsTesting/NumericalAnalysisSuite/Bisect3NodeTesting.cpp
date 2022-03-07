// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:48)

#include "Bisect3NodeTesting.h"
 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect3NodeTesting) 
#include SYSTEM_WARNING_DISABLE(26440)
void Mathematics::Bisect3NodeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NextNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SameSignTest);
}


void Mathematics::Bisect3NodeTesting ::ValueTest()
{
}

void Mathematics::Bisect3NodeTesting
	::NextNodeTest()
{
    
}

void Mathematics::Bisect3NodeTesting
	::SameSignTest()
{
     
}

