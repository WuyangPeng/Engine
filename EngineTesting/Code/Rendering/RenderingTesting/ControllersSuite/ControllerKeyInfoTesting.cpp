// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 16:36)

#include "ControllerKeyInfoTesting.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ControllerKeyInfoTesting) 

void Rendering::ControllerKeyInfoTesting
	::MainTest()
{	 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::ControllerKeyInfoTesting
	::InitTest()
{
	 ControllerKeyInfo firstMorphControllerInfo(3.0f,5,16);

	 ASSERT_APPROXIMATE(firstMorphControllerInfo.GetNormTime(), 3.0f, 1e-8f);
	 ASSERT_EQUAL(firstMorphControllerInfo.GetFirstIndex(), 5);
	 ASSERT_EQUAL(firstMorphControllerInfo.GetSecondIndex(), 16);
}
 