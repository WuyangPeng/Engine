///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:34)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::UniqueContainerGetFunctionDefinitionParsing::UniqueContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueContainerGetFunctionDefinitionParsing)

System::String CoreTools::UniqueContainerGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetFunction();

    content += GenerateReturn(lowerClassName);

    return content;
}

System::String CoreTools::UniqueContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_FunctionConst;
    content += TextParsing::g_Noexcept;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::UniqueContainerGetFunctionDefinitionParsing::GenerateReturn(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();
    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Return;
    content += lowerClassName;
    content += TextParsing::g_SemicolonNewline;

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}
