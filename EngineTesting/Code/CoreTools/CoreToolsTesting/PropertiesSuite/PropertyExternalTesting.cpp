// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "PropertyExternalTesting.h" 
#include "Detail/PropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PropertyExternalTesting)

void CoreTools::PropertyExternalTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::PropertyExternalTesting
	::GetSetTest()
{
	PropertyExternal simplePropertyExternal{};

	string value{ simplePropertyExternal.m_GetType };

	ASSERT_EQUAL(value, "");

	string setValue{ "set" };

	simplePropertyExternal.m_SetType = setValue;

	value = simplePropertyExternal.m_GetSetType;

	ASSERT_EQUAL(value, setValue);

	simplePropertyExternal.m_GetSetType = setValue + setValue;

	value = simplePropertyExternal.m_GetType;

	ASSERT_EQUAL(value, setValue + setValue);
}


