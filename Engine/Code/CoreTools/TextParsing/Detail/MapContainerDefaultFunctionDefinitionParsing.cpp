///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerDefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapContainerDefaultFunctionDefinitionParsing::MapContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapContainerDefaultFunctionDefinitionParsing)

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateContainerAddDataDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateLoop();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateCSVRowInit();
    content += GenerateCreateSharedPtr();
    content += GenerateEmplaceSharedPtr();
    content += GenerateLog();

    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateLog() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets(2);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateWarnLog(3);
    content += GenerateRepeatKey(4, TextParsing::g_RepeatKeyHint);
    content += GenerateGetKey();
    content += GenerateLogAssert(4);

    content += GenerateFunctionEndBrackets(2);

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateCreateSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto csvHead = GetCSVHead();

    content += TextParsing::g_Auto;
    content += GetLowerClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_MakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_CSVRowParameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateEmplaceSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto name = GetLowerClassName();

    content += TextParsing::g_IfNot;
    content += name;
    content += TextParsing::g_Emplace;
    content += name;
    content += TextParsing::g_BaseGetKey;
    content += TextParsing::g_Comma;
    content += TextParsing::g_Space;
    content += name;
    content += TextParsing::g_BaseSecond;

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(4);

    content += TextParsing::g_Left;
    content += GetLowerClassName();
    content += TextParsing::g_BaseGetKey;
    content += TextParsing::g_NewlineCharacter;

    return content;
}
