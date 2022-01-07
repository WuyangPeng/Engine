///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:42)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "JsonGenerateDefaultFunction.h"
#include "JsonGenerateDetailHeadFile.h"
#include "JsonGenerateGetFunction.h"
#include "JsonGenerateGetFunctionDefinition.h"
#include "JsonGenerateHead.h"
#include "JsonGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateDetailHeadFile::JsonGenerateDetailHeadFile(const JsonHead& jsonHead) noexcept
    : ParentType{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonGenerateDetailHeadFile)

System::String CoreTools::JsonGenerateDetailHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_DetailHeadFileExtensionName;

    return result;
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    const auto head = GetJsonHead();

    content += TextParsing::g_NewlineCharacter;
    content += GenerateHeaderGuard();

    const JsonGenerateHead jsonGenerateHead{ head };
    content += jsonGenerateHead.GenerateContainerDetailHead();

    const JsonGenerateGetFunctionDefinition jsonGenerateGetFunctionDefinition{ head };
    content += jsonGenerateGetFunctionDefinition.GenerateDetailDefinition();

    if (head.HasNested())
    {
        for (const auto& value : head)
        {
            const auto& container = value->GetJsonNodeContainer();
            content += GetContent(value->GetTypeName(), container);
        }
    }

    content += GenerateHeaderGuardEndif();

    return content;
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetContent(const String& className, const JsonNodeContainer& jsonNodeContainer) const
{
    String content{};

    for (const auto& value : jsonNodeContainer)
    {
        if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
        {
            content += GetContent(className, *value);

            const auto& container = value->GetJsonNodeContainer();
            content += GetContent(className, container);
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetContent(const String& className, const JsonNode& jsonNode) const
{
    String content{};

    const auto typeName = jsonNode.GetTypeName();

    if (typeName.empty())
    {
        return content;
    }

    const auto head = GetJsonHead();

    const JsonGenerateGetFunctionDefinition jsonGenerateGetFunctionDefinition{ head };
    content += jsonGenerateGetFunctionDefinition.GenerateDetailDefinition(className, jsonNode);

    return content;
}
