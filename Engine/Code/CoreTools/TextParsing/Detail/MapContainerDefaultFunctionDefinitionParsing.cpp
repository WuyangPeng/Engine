///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:51)

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

    content += GenerateWarnLog(3);
    content += GenerateRepeatKey(0, TextParsing::gRepeatKeyHint);
    content += GenerateGetKey();
    content += GenerateLogAssert(0);

    content += GenerateFunctionEndBrackets(2);

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateCreateSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto csvHead = GetCSVHead();

    content += TextParsing::gAuto;
    content += TextParsing::gSpace;
    content += GetLowerClassName();
    content += TextParsing::gBase;
    content += TextParsing::gSpace;
    content += TextParsing::gEqualSign;
    content += TextParsing::gSpace;
    content += TextParsing::gMakeShared;
    content += TextParsing::gLeftAngleBracket;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gCSVRowParameter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateEmplaceSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto name = GetLowerClassName();

    content += TextParsing::gIfNot;
    content += name;
    content += TextParsing::gEmplace;
    content += name;
    content += TextParsing::gBaseGetKey;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += name;
    content += TextParsing::gBaseSecond;

    return content;
}

System::String CoreTools::MapContainerDefaultFunctionDefinitionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gComma };

    content += TextParsing::gSpace;
    content += GetLowerClassName();
    content += TextParsing::gBaseGetKey;

    return content;
}
