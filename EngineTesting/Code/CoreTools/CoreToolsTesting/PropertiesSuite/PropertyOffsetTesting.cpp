// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "PropertyOffsetTesting.h" 
#include "Detail/PropertyOffset.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PropertyOffsetTesting)

void CoreTools::PropertyOffsetTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetTest);
}

void CoreTools::PropertyOffsetTesting
	::GetTest()
{
	PropertyOffset propertyOffset;

	string offset{ propertyOffset.m_Offset };

	ASSERT_EQUAL(offset, "Value");
	ASSERT_EQUAL(propertyOffset.GetInternalValue(), "Offset");
}


