///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:29)

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
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateSizeZero() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_SizeZero;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateContainerZero() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ThrowException;
    content += GetLowerClassName();
    content += TextParsing::g_ContainerZero;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateMany() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSizeGreaterOne();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateWarnLog(2);
    content += GenerateRepeatKey(3, TextParsing::g_NotUnique);
    content += GenerateLogAssert(3);

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateSizeGreaterOne() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_SizeGreaterOne;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateCreate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCSVRowZeroInit();

    content += TextParsing::g_NewlineCharacter;

    content += GenerateMakeShared();

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateCSVRowZeroInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_CSVRowZeroInit;

    return content;
}

System::String CoreTools::UniqueContainerDefaultFunctionDefinitionParsing::GenerateMakeShared() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += GetLowerClassName();
    content += TextParsing::g_MakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_CSVRowParameter;

    return content;
}
