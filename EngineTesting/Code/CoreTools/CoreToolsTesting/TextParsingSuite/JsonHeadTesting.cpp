///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 16:05)

#include "JsonHeadTesting.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::JsonHeadTesting::JsonHeadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonHeadTesting)

void CoreTools::JsonHeadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonHeadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonHeadTest);
}

void CoreTools::JsonHeadTesting::JsonHeadTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonTesting/Log.json") };

    ASSERT_EQUAL(jsonHead.GetNameSpace(), SYSTEM_TEXT("JsonTesting"s));
    ASSERT_EQUAL(jsonHead.GetJsonClassName(), SYSTEM_TEXT("Log"s));
    ASSERT_EQUAL(jsonHead.GetCompleteClassName(), SYSTEM_TEXT("JsonTesting::Log"s));
    ASSERT_TRUE(jsonHead.HasNested());
    ASSERT_TRUE(jsonHead.HasArray());
    ASSERT_FALSE(jsonHead.HasBoolArray());

    for (const auto& value : jsonHead)
    {
        JsonHeadNodeTest(*value);
    }

    ASSERT_EQUAL(jsonHead.GetSize(), 4);
}

void CoreTools::JsonHeadTesting::JsonHeadNodeTest(const JsonNode& jsonNode)
{
    if (jsonNode.GetTypeName() == SYSTEM_TEXT("Logger"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Nested);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("System"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("CoreTools"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Network"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Database"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Script"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Mathematics"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("SoundEffect"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("InputOutput"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("ResourceManager"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Rendering"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Physics"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Imagics"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Animation"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("ArtificialIntellegence"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("UserInterface"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("AssistTools"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Framework"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Test"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::IntArray);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("ConsoleTest"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::StringArray);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Appender"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::NestedArray);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT(""s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Nested);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Type"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::String);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Directory"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::String);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("FileName"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::String);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Flags"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Level"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("MaxFileSize"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("MaxFileSize"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Backup"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Bool);
    }
    else if (jsonNode.GetTypeName() == SYSTEM_TEXT("Extension"s))
    {
        ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::String);
    }

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        JsonHeadNodeTest(*value);
    }
}
