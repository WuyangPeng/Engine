// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:30)

#include "ObjectNameTesting.h"
#include "CoreTools/ObjectSystems/ObjectName.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectNameTesting)

void CoreTools::ObjectNameTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
}

void CoreTools::ObjectNameTesting
	::NameTest()
{
	string firstString{ "firstName" };
	string secondString{ "secondString" };

	ObjectName firstName{ firstString };
	ObjectName secondName{ firstString };
	ObjectName thirdName{ secondString };

	ASSERT_EQUAL(firstString, firstName.GetName());
	ASSERT_EQUAL(firstString, secondName.GetName());
	ASSERT_EQUAL(secondString, thirdName.GetName());
	ASSERT_TRUE(firstName.IsExactly(firstName));
	ASSERT_TRUE(firstName.IsExactly(secondName));
	ASSERT_FALSE(firstName.IsExactly(thirdName));

	secondName.SetName(secondString);
	ASSERT_EQUAL(secondString, secondName.GetName());

	ASSERT_FALSE(secondName.IsExactly(firstName));
	ASSERT_TRUE(secondName.IsExactly(secondName));
	ASSERT_TRUE(secondName.IsExactly(thirdName));
}

