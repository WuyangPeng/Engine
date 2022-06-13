///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "ObjectNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectName.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectNameTesting)

void CoreTools::ObjectNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
}

void CoreTools::ObjectNameTesting::NameTest()
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
