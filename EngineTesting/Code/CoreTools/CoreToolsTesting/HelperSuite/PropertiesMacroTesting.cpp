///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/18 11:55)

#include "PropertiesMacroTesting.h"
#include "Detail/Properties.h"
#include "Detail/PropertiesFriend.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/PropertiesMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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

    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue6Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesValue9Test);
}

void CoreTools::PropertiesMacroTesting::PropertiesFriendTest()
{
    const PropertiesFriend propertiesFriend{};

    ASSERT_EQUAL(propertiesFriend.GetValue(), 0);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue0Test()
{
    Properties properties{};

    ASSERT_EQUAL(properties.Value0, 1);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue1Test()
{
    Properties properties{};

    ASSERT_EQUAL(properties.Value1, 1);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue2Test()
{
    Properties properties{};

    ASSERT_TRUE(properties.GetValue2().empty());

    const auto newValue = "newValue"s;

    properties.Value2 = newValue;

    ASSERT_EQUAL(properties.GetValue2(), newValue);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue3Test()
{
    Properties properties{};

    ASSERT_EQUAL(properties.Value3, 0u);

    properties.Value3 = 5u;

    ASSERT_EQUAL(properties.Value3, 5u);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue4Test()
{
    Properties properties{};

    ASSERT_EQUAL(properties.Value4, 0);

    properties.Value4 = 2;

    ASSERT_EQUAL(properties.Value4, 2);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue5Test()
{
    Properties properties{};

    auto result = static_cast<std::string>(properties.Value5);
    ASSERT_TRUE(result.empty());

    const auto newValue = "newValue"s;

    properties.Value5 = newValue;

    result = properties.Value5;
    ASSERT_EQUAL(result, newValue);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue6Test()
{
    Properties properties{};

    ASSERT_TRUE(properties.Value6.empty());
}

void CoreTools::PropertiesMacroTesting::PropertiesValue8Test()
{
    Properties properties{};

    const auto newValue = "newValue"s;

    ASSERT_TRUE(properties.GetValue7().empty());
    properties.Value8 = newValue;
    ASSERT_EQUAL(properties.GetValue7(), newValue);
}

void CoreTools::PropertiesMacroTesting::PropertiesValue9Test()
{
    Properties properties{};

    const auto newValue = "newValue"s;

    ASSERT_TRUE(properties.Value9.empty());
    properties.Value9 = newValue;
    ASSERT_EQUAL(properties.Value9, newValue);
}
