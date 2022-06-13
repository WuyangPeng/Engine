///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:38)

#include "PropertiesMacroTesting.h"
#include "Detail/Properties.h"
#include "Detail/PropertiesFriend.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/PropertiesMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using namespace std::literals;

CoreTools::PropertiesMacroTesting::PropertiesMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertiesMacroTesting)

void CoreTools::PropertiesMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertiesMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesFriendTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesTest);
}

void CoreTools::PropertiesMacroTesting::PropertiesFriendTest()
{
    const PropertiesFriend propertiesFriend{};

    ASSERT_EQUAL(propertiesFriend.GetValue(), 0);
}

void CoreTools::PropertiesMacroTesting::PropertiesTest()
{
    Properties properties{};

    ASSERT_EQUAL(properties.Value0, 1);
    ASSERT_EQUAL(properties.Value1, 1);

    ASSERT_EQUAL(properties.GetValue2(), ""s);

    auto stringValue = "newValue"s;

    properties.Value2 = stringValue;

    ASSERT_EQUAL(properties.GetValue2(), stringValue);

    ASSERT_EQUAL(properties.Value3, 0u);

    properties.Value3 = 5u;

    ASSERT_EQUAL(properties.Value3, 5u);

    ASSERT_EQUAL(properties.Value4, 0);

    properties.Value4 = 2;

    ASSERT_EQUAL(properties.Value4, 2);

    auto result = static_cast<string>(properties.Value5);
    ASSERT_EQUAL(result, "");

    properties.Value5 = stringValue;

    result = properties.Value5;
    ASSERT_EQUAL(result, stringValue);

    ASSERT_EQUAL(properties.Value6, "");

    ASSERT_EQUAL(properties.GetValue7(), "");
    properties.Value8 = stringValue;
    ASSERT_EQUAL(properties.GetValue7(), stringValue);

    ASSERT_EQUAL(properties.Value9, "");
    properties.Value9 = stringValue;
    ASSERT_EQUAL(properties.Value9, stringValue);
}
