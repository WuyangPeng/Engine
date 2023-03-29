///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "StringCastEnumDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::StringCastEnumDefinitionParsing::StringCastEnumDefinitionParsing(CSVHead csvHead, String className) noexcept
    : ParentType{ 0 }, className{ std::move(className) }, head{ std::move(csvHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringCastEnumDefinitionParsing)

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateStringCastEnumFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateStringCastEnum(false);

    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateStringCastEnumDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateStringCastEnum(true);

    content += GenerateFunctionBeginBrackets();

    content += GenerateIndentation(1);
    content += TextParsing::gCoreToolsClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;
    content += GenerateDescribe();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateStringCastEnum(bool isDefinition) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = head.GetNameSpace();

    auto content = GenerateIndentation();

    content += TextParsing::gTemplateSpecialization;
    if (!isDefinition)
    {
        content += TextParsing::gNodiscard;
    }

    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gCSVRowStringCastEnum;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDescribeConst;

    return content;
}

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = head.GetNameSpace();

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gStringCast;
    content += className;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gEnumDescribe;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    return content;
}
