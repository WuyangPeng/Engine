///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.6 (2021/11/09 20:46)

#include "JsonNodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::vector;
using namespace std::literals;

CoreTools::JsonNodeTesting::JsonNodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonNodeTesting)

void CoreTools::JsonNodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonNodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonNodeContainerTest);
}

void CoreTools::JsonNodeTesting::JsonNodeTest()
{
    JsonNode jsonNode{ SYSTEM_TEXT("Key"), JsonDataType::Int };

    ASSERT_EQUAL(jsonNode.GetTypeName(), SYSTEM_TEXT("Key"s));
    ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::Int);

    jsonNode.SetNewJsonDataType(JsonDataType::Double);
    ASSERT_ENUM_EQUAL(jsonNode.GetJsonDataType(), JsonDataType::String);

    ASSERT_FALSE(jsonNode.HasArray());
    ASSERT_FALSE(jsonNode.HasBoolArray());
}

void CoreTools::JsonNodeTesting::JsonNodeContainerTest()
{
    auto jsonNodeContainer0 = JsonNodeContainer::Create();
    auto jsonNode0 = make_shared<JsonNode>(SYSTEM_TEXT("Key"s), JsonDataType::Bool);
    jsonNodeContainer0.AddJsonNode(jsonNode0);

    JsonNode jsonNode1{ SYSTEM_TEXT("Container"), JsonDataType::Nested };
    jsonNode1.SetNewJsonNodeContainer(jsonNodeContainer0);

    auto jsonNodeContainer1 = jsonNode1.GetJsonNodeContainer();

    ASSERT_ENUM_EQUAL(jsonNodeContainer1.GetJsonDataType(SYSTEM_TEXT("Key"s)), JsonDataType::Bool);
}
