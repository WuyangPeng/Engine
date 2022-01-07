///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:44)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "JsonGenerateDefaultFunction.h"
#include "JsonGenerateGetFunction.h"
#include "JsonGenerateHead.h"
#include "JsonGenerateHeadFile.h"
#include "JsonGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateHeadFile::JsonGenerateHeadFile(const JsonHead& jsonHead) noexcept
    : ParentType{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonGenerateHeadFile)

System::String CoreTools::JsonGenerateHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::JsonGenerateHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::JsonGenerateHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_HeadFileExtensionName;

    return result;
}

System::String CoreTools::JsonGenerateHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    const auto head = GetJsonHead();

    content += TextParsing::g_NewlineCharacter;
    content += GenerateHeaderGuard();

    JsonGenerateHead jsonGenerateHead{ head };
    content += jsonGenerateHead.GenerateCoreToolsHead();

    content += GenerateNameSpace();

    JsonGenerateClassName jsonGenerateClassName{ head };
    content += jsonGenerateClassName.GenerateContainerClassName();
    content += jsonGenerateClassName.GenerateUsing();
    content += TextParsing::g_NewlineCharacter;

    JsonGenerateDefaultFunction jsonGenerateDefaultFunction{ head };
    content += jsonGenerateDefaultFunction.GenerateContainerDefaultFunction();

    JsonGenerateGetFunction jsonGenerateGetFunction{ head };
    content += jsonGenerateGetFunction.GenerateContainerFunction();

    JsonGenerateMember jsonGenerateMember{ head };
    content += jsonGenerateMember.GenerateContainerMember();

    if (head.HasNested())
    {
        content += GenerateInnerNameSpaceBegin();

        for (const auto& value : head)
        {
            if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
            {
                content += GetContent(*value);

                const auto& container = value->GetJsonNodeContainer();
                content += GetContent(container);
            }
        }

        content += GenerateInnerNameSpaceEnd();
    }

    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    content += GenerateHeaderGuardEndif();

    return content;
}

System::String CoreTools::JsonGenerateHeadFile::GetContent(const JsonNodeContainer& jsonNodeContainer) const
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

System::String CoreTools::JsonGenerateHeadFile::GetContent(const JsonNode& jsonNode) const
{
    String content{};

    const auto className = jsonNode.GetTypeName();

    if (className.empty())
    {
        return content;
    }

    const auto head = GetJsonHead();

    JsonGenerateClassName jsonGenerateClassName{ head };
    content += jsonGenerateClassName.GenerateContainerClassName(jsonNode);
    content += jsonGenerateClassName.GenerateUsing(jsonNode);
    content += TextParsing::g_NewlineCharacter;

    JsonGenerateDefaultFunction jsonGenerateDefaultFunction{ head };
    content += jsonGenerateDefaultFunction.GenerateContainerDefaultFunction(jsonNode);

    JsonGenerateGetFunction jsonGenerateGetFunction{ head };
    content += jsonGenerateGetFunction.GenerateContainerFunction(jsonNode);

    JsonGenerateMember jsonGenerateMember{ head };
    content += jsonGenerateMember.GenerateContainerMember(jsonNode);

    return content;
}
