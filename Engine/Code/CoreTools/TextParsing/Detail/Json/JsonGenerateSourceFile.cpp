///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:47)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "JsonGenerateDefaultFunction.h"
#include "JsonGenerateDefaultFunctionDefinition.h"
#include "JsonGenerateGetFunction.h"
#include "JsonGenerateGetFunctionDefinition.h"
#include "JsonGenerateHead.h"
#include "JsonGenerateMember.h"
#include "JsonGenerateSourceFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateSourceFile::JsonGenerateSourceFile(const JsonHead& jsonHead) noexcept
    : ParentType{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonGenerateSourceFile)

System::String CoreTools::JsonGenerateSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::JsonGenerateSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::JsonGenerateSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_SourceFileExtensionName;

    return result;
}

System::String CoreTools::JsonGenerateSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    const auto head = GetJsonHead();

    content += TextParsing::g_NewlineCharacter;

    const JsonGenerateHead jsonGenerateHead{ head };
    content += jsonGenerateHead.GenerateContainerSourceHead();

    const JsonGenerateDefaultFunctionDefinition jsonGenerateDefaultFunctionDefinition{ head };
    content += jsonGenerateDefaultFunctionDefinition.GenerateDefinition();

    const JsonGenerateGetFunctionDefinition jsonGenerateGetFunctionDefinition{ head };
    content += jsonGenerateGetFunctionDefinition.GenerateDefinition();

    if (head.HasNested())
    {
        for (const auto& value : head)
        {
            if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
            {
                content += GetContent(*value);

                const auto& container = value->GetJsonNodeContainer();
                content += GetContent(container);
            }
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateSourceFile::GetContent(const JsonNodeContainer& jsonNodeContainer) const
{
    String content{};

    for (const auto& value : jsonNodeContainer)
    {
        if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
        {
            content += GetContent(*value);

            const auto& container = value->GetJsonNodeContainer();
            content += GetContent(container);
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateSourceFile::GetContent(const JsonNode& jsonNode) const
{
    String content{};

    const auto typeName = jsonNode.GetTypeName();

    if (typeName.empty())
    {
        return content;
    }

    const auto head = GetJsonHead();

    const JsonGenerateDefaultFunctionDefinition jsonGenerateDefaultFunctionDefinition{ head };
    content += jsonGenerateDefaultFunctionDefinition.GenerateDefinition(jsonNode);

    const JsonGenerateGetFunctionDefinition jsonGenerateGetFunctionDefinition{ head };
    content += jsonGenerateGetFunctionDefinition.GenerateDefinition(jsonNode);

    return content;
}