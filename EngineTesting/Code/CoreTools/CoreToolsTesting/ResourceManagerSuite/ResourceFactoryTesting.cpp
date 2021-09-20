// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:18)

#include "ResourceFactoryTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ResourceFactoryTesting)

void CoreTools::ResourceFactoryTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
}

void CoreTools::ResourceFactoryTesting ::FactoryTest() noexcept
{
	 
}