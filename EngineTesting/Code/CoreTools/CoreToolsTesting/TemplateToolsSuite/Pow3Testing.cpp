// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:05)

#include "Pow3Testing.h"
#include "CoreTools/TemplateTools/Pow3.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, Pow3Testing)

void CoreTools::Pow3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(Pow3Test);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)
void CoreTools::Pow3Testing
	::Pow3Test()
{
	ASSERT_EQUAL(Pow3<5>::Result, 3 * 3 * 3 * 3 * 3);
	ASSERT_EQUAL(Pow3<4>::Result, 3 * 3 * 3 * 3);
	ASSERT_EQUAL(Pow3<7>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3);
	ASSERT_EQUAL(Pow3<10>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3);
}
#include STSTEM_WARNING_POP