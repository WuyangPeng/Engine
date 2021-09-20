// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:04)

#include "IncrementScopeTesting.h"
#include "CoreTools/TemplateTools/IncrementScopeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, IncrementScopeTesting)

void CoreTools::IncrementScopeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ScopeTest);
}

void CoreTools::IncrementScopeTesting
	::ScopeTest()
{
	auto value = 0;

	ASSERT_EQUAL(value, 0);

	{
		IncrementScope<int> incrementScope(value);

		ASSERT_EQUAL(value, 1);
	}

	ASSERT_EQUAL(value, 0);

	{
		IncrementScope<int, SimpleDecrementer<int>, SimpleIncrementer<int> > incrementScope(value);

		ASSERT_EQUAL(value, -1);
	}

	ASSERT_EQUAL(value, 0);
}

