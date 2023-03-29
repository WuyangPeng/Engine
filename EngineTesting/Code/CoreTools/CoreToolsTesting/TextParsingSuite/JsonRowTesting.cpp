///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/14 14:54)

#include "JsonRowTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <CoreTools/CharacterString/StringConversion.h>

using namespace std::literals;

CoreTools::JsonRowTesting::JsonRowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonRowTesting)

void CoreTools::JsonRowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonRowTest);
}

void CoreTools::JsonRowTesting::JsonRowTest()
{
    JsonRow::BasicTree basicTree{ SYSTEM_TEXT("Resource/JsonConfigure/Monsters.json"s) };
    read_json("Resource/JsonConfigure/Monsters.json"s, basicTree);

    const JsonRow jsonRow{ basicTree };

    ASSERT_EQUAL(jsonRow.GetInt(SYSTEM_TEXT("system"s)), 5);
    ASSERT_EQUAL(jsonRow.GetInt(SYSTEM_TEXT("coreTools"s)), 1);
    ASSERT_EQUAL(jsonRow.GetString(SYSTEM_TEXT("network"s)), SYSTEM_TEXT("Console"s));

    const std::vector test{ 1, 2, 3 };
    ASSERT_EQUAL(jsonRow.GetIntArray(SYSTEM_TEXT("test"s)), test);

    const std::vector<System::String> consoleTest{ SYSTEM_TEXT("1"), SYSTEM_TEXT("Console"), SYSTEM_TEXT("3") };
    ASSERT_EQUAL(jsonRow.GetStringArray(SYSTEM_TEXT("consoleTest"s)), consoleTest);
}
