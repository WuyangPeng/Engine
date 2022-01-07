///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:59)

#include "CoreTools/CoreToolsExport.h"

#include "EnumFunctionDefinitionParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::EnumFunctionDefinitionParsing::EnumFunctionDefinitionParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex)
    : ParentType{ 0 }, m_CsvHead{ csvHead }, m_CsvContent{ csvContent }, className{ className }, nameIndex{ nameIndex }
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

    String space(typeDescribe.size(), TextParsing::g_Space);
    content += GenerateColumn(space);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateFindFunctionDefinition();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

CoreTools::CSVHead CoreTools::EnumFunctionDefinitionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CsvHead;
}

CoreTools::CSVContent CoreTools::EnumFunctionDefinitionParsing::GetCSVContent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CsvContent;
}

int CoreTools::EnumFunctionDefinitionParsing::GetNameIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nameIndex;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GetColumn(const String& describe, const String& space, CSVPoistionType csvPoistionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvPoistionType != CSVPoistionType::Begin)
    {
        content += space;
    }

    content += describe;

    if (csvPoistionType != CSVPoistionType::End)
    {
        content += TextParsing::g_Comma;
        content += TextParsing::g_NewlineCharacter;
    }
    else
    {
        content += TextParsing::g_Space;
        content += TextParsing::g_ClassEndBrackets;
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

    content += TextParsing::g_FindTypeDescribe;
    content += variable;
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_SemicolonNewline;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateIterTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_IterTypeDescribe;

    return content;
}

System::String CoreTools::EnumFunctionDefinitionParsing::GenerateTypeDescribeNotFind() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ThrowException;
    content += TextParsing::g_TypeDescribeNotFind;

    return content;
}