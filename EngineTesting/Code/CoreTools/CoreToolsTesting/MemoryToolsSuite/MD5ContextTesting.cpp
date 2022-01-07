// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MD5ContextTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MD5ContextTesting)

void CoreTools::MD5ContextTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MD5Test);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
void CoreTools::MD5ContextTesting
	::MD5Test()
{
     
}
#include STSTEM_WARNING_POP