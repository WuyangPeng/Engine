///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:56)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultContainerDefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::DefaultContainerDefaultFunctionDefinitionParsing::DefaultContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultContainerDefaultFunctionDefinitionParsing)

System::String CoreTools::DefaultContainerDefaultFunctionDefinitionParsing::GenerateContainerAddDataDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateInit();

    content += GenerateFind();
    content += GenerateLog();

    return content;
}

System::String CoreTools::DefaultContainerDefaultFunctionDefinitionParsing::GenerateFind() const
{
    auto content = GenerateSort();

    content += GenerateReturnKeyLess();
    content += GenerateLambdaEnd();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateUnique();
    content += GenerateReturnKeyEqual();
    content += GenerateLambdaEnd();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::DefaultContainerDefaultFunctionDefinitionParsing::GenerateLog() const
{
    auto content = GenerateIfIter();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateWarnLog(2);
    content += GenerateRepeatKey(3, TextParsing::g_RepeatKey);
    content += GenerateLogAssert(3);
    content += TextParsing::g_NewlineCharacter;
    content += GenerateEraseIter();

    content += GenerateFunctionEndBrackets(1);

    return content;
}
