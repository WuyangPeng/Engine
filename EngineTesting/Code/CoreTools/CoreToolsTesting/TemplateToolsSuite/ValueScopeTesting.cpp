// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:17)

#include "ValueScopeTesting.h"
#include "CoreTools/TemplateTools/ValueScopeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ValueScopeTesting)

void CoreTools::ValueScopeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ValueScopeTesting
	::CastTest()
{
	auto value1 = 33;

	ASSERT_EQUAL(value1, 33);
	{
		ValueScope<int> valueScope{ value1, 20 };

		ASSERT_EQUAL(value1, 20);
	}
	ASSERT_EQUAL(value1, 33);

	int value2{ 33 };

	ASSERT_EQUAL(value2, 33);
	{
		ValueScope<int> valueScope{ value2, 20, 10 };

		ASSERT_EQUAL(value2, 20);
	}
	ASSERT_EQUAL(value2, 10);

	string value3{ "Original 1" };

	ASSERT_EQUAL(value3, "Original 1");
	{
		ValueScope<string>  valueScope{ value3, "Rebel" };

		ASSERT_EQUAL(value3, "Rebel");
	}
	ASSERT_EQUAL(value3, "Original 1");

	string value4{ "Original 2" };

	ASSERT_EQUAL(value4, "Original 2");
	{
		ValueScope<string>  firstValueScope{ value4, "Matthew", "woz 'ere" };

		ASSERT_EQUAL(value4, "Matthew");

		string  sarah{ "Sarah" };
		string  isOut{ "is out" };
		ValueScope<string>  secondValueScope{ value4, sarah, isOut };

		ASSERT_EQUAL(value4, "Sarah");
	}
	ASSERT_EQUAL(value4, "woz 'ere");

}
