// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "DirectPropertyInternalTesting.h" 
#include "Detail/DirectPropertyInternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DirectPropertyInternalTesting)

void CoreTools::DirectPropertyInternalTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::DirectPropertyInternalTesting
	::GetSetTest()
{
	DirectPropertyInternal directPropertyInternal{};

	string value{ directPropertyInternal.m_GetType };

	ASSERT_EQUAL(value, "Init");

	string setValue{ "set" };

	directPropertyInternal.SetValue(setValue);

	value = directPropertyInternal.m_GetType;

	ASSERT_EQUAL(value, setValue);

	ASSERT_EQUAL("SetType", directPropertyInternal.GetValue());

	directPropertyInternal.m_SetType = setValue;

	ASSERT_EQUAL(setValue, directPropertyInternal.GetValue());
}


