// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:43)

#include "StaticPropertyExternalTesting.h" 
#include "Detail/StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StaticPropertyExternalTesting)

void CoreTools::StaticPropertyExternalTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::StaticPropertyExternalTesting
	::GetSetTest()
{
	StaticPropertyExternal StaticPropertyExternal{};

	string value{ StaticPropertyExternal.sm_GetExternalType };

	ASSERT_EQUAL(value, "");

	string setValue{ "set" };

	StaticPropertyExternal.sm_SetExternalType = setValue;

	value = StaticPropertyExternal.sm_GetSetExternalType;

	ASSERT_EQUAL(value, setValue);

	StaticPropertyExternal.sm_GetSetExternalType = setValue + setValue;

	value = StaticPropertyExternal.sm_GetExternalType;

	ASSERT_EQUAL(value, setValue + setValue);

	StaticPropertyExternal.m_GetSetType = setValue + setValue + setValue;

	value = StaticPropertyExternal.m_GetSetType;

	ASSERT_EQUAL(value, setValue + setValue + setValue);
}


