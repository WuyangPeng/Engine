///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:50)

#include "JsonNodeContainerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;
using std::make_shared;
using std::vector;

CoreTools::JsonNodeContainerTesting::JsonNodeContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonNodeContainerTesting)

void CoreTools::JsonNodeContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonNodeContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IsEmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddJsonNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetNewJsonDataTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetNewJsonNodeContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetJsonDataTypeTest);
}

void CoreTools::JsonNodeContainerTesting::IsEmptyTest()
{
    auto jsonNodeContainer = JsonNodeContainer::Create();

    ASSERT_EQUAL(jsonNodeContainer.GetSize(), 0);
    ASSERT_TRUE(jsonNodeContainer.IsEmpty());
    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(SYSTEM_TEXT("Key"s)), JsonDataType::Null);

    auto jsonNode = make_shared<JsonNode>(SYSTEM_TEXT("Key"s), JsonDataType::Bool);
    jsonNodeContainer.AddJsonNode(jsonNode);
    ASSERT_FALSE(jsonNodeContainer.IsEmpty());
    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(SYSTEM_TEXT("Key"s)), JsonDataType::Bool);

    ASSERT_TRUE(jsonNodeContainer.HasNested());
    ASSERT_FALSE(jsonNodeContainer.HasArray());
    ASSERT_FALSE(jsonNodeContainer.HasBoolArray());

    ASSERT_EQUAL(jsonNodeContainer.GetSize(), 1);
}

void CoreTools::JsonNodeContainerTesting::AddJsonNodeTest()
{
    auto jsonNodeContainer = JsonNodeContainer::Create();
    auto jsonNode = make_shared<JsonNode>(SYSTEM_TEXT("Key"s), JsonDataType::Bool);
    jsonNodeContainer.AddJsonNode(jsonNode);

    for (const auto& value : jsonNodeContainer)
    {
        ASSERT_EQUAL(value, jsonNode);
    }

    auto jsonNodeContainer1 = JsonNodeContainer::Create();
    jsonNodeContainer1.AddJsonNode(jsonNodeContainer);

    for (const auto& value : jsonNodeContainer1)
    {
        ASSERT_EQUAL(value, jsonNode);
    }
}

void CoreTools::JsonNodeContainerTesting::SetNewJsonDataTypeTest()
{
    auto jsonNodeContainer = JsonNodeContainer::Create();

    auto jsonNode = make_shared<JsonNode>(SYSTEM_TEXT("Key"s), JsonDataType::Bool);
    jsonNodeContainer.AddJsonNode(jsonNode);
    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(SYSTEM_TEXT("Key"s)), JsonDataType::Bool);

    jsonNodeContainer.SetNewJsonDataType(SYSTEM_TEXT("Key"s), JsonDataType::String);
    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(SYSTEM_TEXT("Key"s)), JsonDataType::String);
}

void CoreTools::JsonNodeContainerTesting::SetNewJsonNodeContainerTest()
{
    auto jsonNodeContainer0 = JsonNodeContainer::Create();

    auto jsonNode0 = make_shared<JsonNode>(SYSTEM_TEXT("Key0"s), JsonDataType::Bool);
    jsonNodeContainer0.AddJsonNode(jsonNode0);

    auto jsonNode1 = make_shared<JsonNode>(SYSTEM_TEXT("Key1"s), JsonDataType::Bool);
    jsonNodeContainer0.AddJsonNode(jsonNode1);

    JsonNode jsonNode2{ SYSTEM_TEXT("Container"s), JsonDataType::Nested };
    jsonNode2.SetNewJsonNodeContainer(jsonNodeContainer0);

    auto jsonNodeContainer1 = JsonNodeContainer::Create();

    auto jsonNode3 = make_shared<JsonNode>(SYSTEM_TEXT("NewKey"s), JsonDataType::Bool);
    jsonNodeContainer1.AddJsonNode(jsonNode3);

    jsonNode2.SetNewJsonNodeContainer(jsonNodeContainer1);

    auto size = 0;
    for (const auto& value : jsonNode2.GetJsonNodeContainer())
    {
        ++size;
        ASSERT_ENUM_EQUAL(value->GetJsonDataType(), JsonDataType::Bool);

        ASSERT_UNEQUAL(value->GetTypeName().find(SYSTEM_TEXT("Key"s)), System::String::npos);
    }

    ASSERT_EQUAL(size, 3);

    ASSERT_TRUE(jsonNode2.GetJsonNodeContainer().HasNested());
}

void CoreTools::JsonNodeContainerTesting::SetJsonDataTypeTest()
{
    auto jsonNodeContainer = JsonNodeContainer::Create();
    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(), JsonDataType::Nested);

    jsonNodeContainer.SetJsonDataType(JsonDataType::String);

    ASSERT_ENUM_EQUAL(jsonNodeContainer.GetJsonDataType(), JsonDataType::StringArray);

    ASSERT_FALSE(jsonNodeContainer.HasNested());
}
