///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:36)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueContainerDefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::UniqueContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueContainerDefaultFunctionDefinitionParsing)

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateContainerAddDataDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateZero();

    content += GenerateMany();
    content += GenerateCreate();

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateZero() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSizeZero();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateContainerZero();

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateSizeZero() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gSizeZero;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateContainerZero() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gThrowException;
    content += GetLowerClassName();
    content += TextParsing::gContainerZero;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateMany() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSizeGreaterOne();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateWarnLog(2);
    content += GenerateRepeatKey(0, TextParsing::gNotUnique);
    content += GenerateLogAssert(0);

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateSizeGreaterOne() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gSizeGreaterOne;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateCreate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCSVRowZeroInit();

    content += TextParsing::gNewlineCharacter;

    content += GenerateMakeShared();

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateCSVRowZeroInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gCSVRowZeroInit;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateMakeShared() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += GetLowerClassName();
    content += TextParsing::gSpace;
    content += TextParsing::gEqualSign;
    content += TextParsing::gSpace;
    content += TextParsing::gMakeShared;
    content += TextParsing::gLeftAngleBracket;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gCSVRowParameter;

    return content;
}
