// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "MethodPropertyTesting.h"
#include "Detail/MethodProperty.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MethodPropertyTesting)

void CoreTools::MethodPropertyTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetTest);
}

void CoreTools::MethodPropertyTesting
	::GetTest()
{
	MethodProperty methodProperty;

	ASSERT_EQUAL(methodProperty.m_GetType, 0);

	methodProperty.m_SetType = 1;

	ASSERT_EQUAL(methodProperty.m_GetSetType, 1);

	methodProperty.m_GetSetType = 2;

	ASSERT_EQUAL(methodProperty.m_GetType, 2);

	methodProperty.m_SetExternalType = 3;

	ASSERT_EQUAL(methodProperty.m_GetSetExternalType, 3);

	methodProperty.m_GetSetExternalType = 4;

	ASSERT_EQUAL(methodProperty.m_GetExternalType, 4);
}


