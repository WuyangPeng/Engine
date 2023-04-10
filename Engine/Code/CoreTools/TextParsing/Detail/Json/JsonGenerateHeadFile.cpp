///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:26)

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
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::JsonGenerateHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::JsonGenerateHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    const auto head = GetJsonHead();

    content += TextParsing::gNewlineCharacter;
    content += GenerateHeaderGuard();

    JsonGenerateHead jsonGenerateHead{ head };
    content += jsonGenerateHead.GenerateCoreToolsHead();

    content += GenerateNameSpace();

    JsonGenerateClassName jsonGenerateClassName{ head };
    content += jsonGenerateClassName.GenerateContainerClassName();
    content += jsonGenerateClassName.GenerateUsing();
    content += TextParsing::gNewlineCharacter;

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

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

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

    if (const auto className = jsonNode.GetTypeName(); className.empty())
    {
        return content;
    }

    content += JsonGenerateClassName::GenerateContainerClassName(jsonNode);
    content += JsonGenerateClassName::GenerateUsing(jsonNode);
    content += TextParsing::gNewlineCharacter;

    content += JsonGenerateDefaultFunction::GenerateContainerDefaultFunction(jsonNode);

    content += JsonGenerateGetFunction::GenerateContainerFunction(jsonNode);

    const auto head = GetJsonHead();
    const JsonGenerateMember jsonGenerateMember{ head };
    content += jsonGenerateMember.GenerateContainerMember(jsonNode);

    return content;
}
