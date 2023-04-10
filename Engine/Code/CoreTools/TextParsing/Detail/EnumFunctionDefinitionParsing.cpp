///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:53)

#include "CoreTools/CoreToolsExport.h"

#include "EnumFunctionDefinitionParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::EnumFunctionDefinitionParsing::EnumFunctionDefinitionParsing(CSVHead csvHead, CSVContent csvContent, String className, int nameIndex) noexcept
    : ParentType{ 0 }, head{ std::move(csvHead) }, csvContent{ std::move(csvContent) }, className{ std::move(className) }, nameIndex{ nameIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumFunctionDefinitionParsing)

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateEnumFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateHeader();

    content += GenerateFunctionBeginBrackets();

    const auto typeDescribe = GenerateDescribe();
    content += typeDescribe;

    const String space(typeDescribe.size(), TextParsing::gSpace);
    content += GenerateColumn(space);
    content += TextParsing::gNewlineCharacter;

    content += GenerateFindFunctionDefinition();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::CSVHead CoreTools::EnumFunctionDefinitionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head;
}

CoreTools::CSVContent CoreTools::EnumFunctionDefinitionParsing::GetCSVContent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvContent;
}

int CoreTools::EnumFunctionDefinitionParsing::GetNameIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nameIndex;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GetColumn(const String& describe, const String& space, CSVPositionType csvPositionType)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvPositionType != CSVPositionType::Begin)
    {
        content += space;
    }

    content += describe;

    if (csvPositionType != CSVPositionType::End)
    {
        content += TextParsing::gComma;
        content += TextParsing::gNewlineCharacter;
    }
    else
    {
        content += TextParsing::gSpace;
        content += TextParsing::gClassEndBrackets;
    }

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GetFindFunctionDefinition(const StringView& variable) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFindTypeDescribe(variable);

    content += GenerateIterTypeDescribe();

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateReturnIterSecond();
    content += GenerateFunctionEndBrackets(1);

    content += GenerateElse(1);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateTypeDescribeNotFind();
    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateFindTypeDescribe(const StringView& variable) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gFindTypeDescribe;
    content += variable;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateIterTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIterTypeDescribe;

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateTypeDescribeNotFind() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gThrowException;
    content += TextParsing::gTypeDescribeNotFind;

    return content;
}