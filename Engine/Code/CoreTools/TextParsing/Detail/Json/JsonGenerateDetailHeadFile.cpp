///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:25)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "JsonGenerateDefaultFunction.h"
#include "JsonGenerateDetailHeadFile.h"
#include "JsonGenerateGetFunctionDefinition.h"
#include "JsonGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

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
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gDetailHeadFileExtensionName;

    return result;
}

System::String CoreTools::JsonGenerateDetailHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    const auto head = GetJsonHead();

    content += TextParsing::gNewlineCharacter;
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

    if (const auto typeName = jsonNode.GetTypeName(); typeName.empty())
    {
        return content;
    }

    const auto head = GetJsonHead();

    const JsonGenerateGetFunctionDefinition jsonGenerateGetFunctionDefinition{ head };
    content += jsonGenerateGetFunctionDefinition.GenerateDetailDefinition(className, jsonNode);

    return content;
}
