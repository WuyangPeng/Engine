///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 14:31)

#include "ObjectNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectName.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectNameTesting::ObjectNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectNameTesting)

void CoreTools::ObjectNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ObjectNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
}

void CoreTools::ObjectNameTesting::NameTest()
{
    const std::string string0{ "string0" };
    const std::string string1{ "string1" };

    const ObjectName objectName0{ string0 };
    ObjectName objectName1{ string0 };
    const ObjectName objectName2{ string1 };

    ASSERT_EQUAL(string0, objectName0.GetName());
    ASSERT_EQUAL(string0, objectName1.GetName());
    ASSERT_EQUAL(string1, objectName2.GetName());
    ASSERT_TRUE(objectName0.IsExactly(objectName0));
    ASSERT_TRUE(objectName0.IsExactly(objectName1));
    ASSERT_FALSE(objectName0.IsExactly(objectName2));

    objectName1.SetName(string1);
    ASSERT_EQUAL(string1, objectName1.GetName());

    ASSERT_FALSE(objectName1.IsExactly(objectName0));
    ASSERT_TRUE(objectName1.IsExactly(objectName1));
    ASSERT_TRUE(objectName1.IsExactly(objectName2));
}
