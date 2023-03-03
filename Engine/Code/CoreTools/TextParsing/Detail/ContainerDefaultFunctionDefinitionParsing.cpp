///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "ContainerDefaultFunctionDefinitionParsing.h"
#include "DefaultContainerDefaultFunctionDefinitionParsing.h"
#include "MapContainerDefaultFunctionDefinitionParsing.h"
#include "UniqueContainerDefaultFunctionDefinitionParsing.h"
#include "VectorContainerDefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ContainerDefaultFunctionDefinitionParsing::ContainerDefaultFunctionDefinitionParsingSharedPtr CoreTools::ContainerDefaultFunctionDefinitionParsing::Create(const CSVHead& csvHead, const String& className)
{
    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Vector:
        {
            return std::make_shared<VectorContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        break;
        case CSVFormatType::Unique:
        {
            return std::make_shared<UniqueContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        break;
        default:
        {
            return std::make_shared<DefaultContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        break;
    }
}

CoreTools::ContainerDefaultFunctionDefinitionParsing::ContainerDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }, lowerClassName{ StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerDefaultFunctionDefinitionParsing)

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateConstructor(TextParsing::g_CSVContent);

    content += GenerateContainerMember();

    content += GenerateFunctionBeginBrackets();

    content += GenerateContainerParsing();
    content += GenerateUserSelfClassIsValid9(1);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerParsingFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateContainerParsingFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateContainerSize();
    content += GenerateContainerAddDataDefinition();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Colon;
    content += TextParsing::g_Space;
    content += lowerClassName;
    content += TextParsing::g_Init;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerParsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ParsingContent;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerParsingFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::g_Void };

    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Parsing;
    content += TextParsing::g_CSVContent;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ContentSize;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLoop() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Loop;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateCSVRowInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_CSVRowInit;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateEmplaceBack() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto csvHead = GetCSVHead();

    content += lowerClassName;
    content += TextParsing::g_EmplaceBack;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_CSVRowCall;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateSort() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Sort;
    content += lowerClassName;
    content += TextParsing::g_Begin;
    content += lowerClassName;
    content += TextParsing::g_Function;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateReturnKeyLess() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ReturnKeyLess;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateReturnKeyEqual() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ReturnKeyEqual;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLambdaEnd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_LambdaEnd;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateUnique() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Unique;
    content += lowerClassName;
    content += TextParsing::g_Begin;
    content += lowerClassName;
    content += TextParsing::g_Function;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateIfIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_IfIter;
    content += lowerClassName;
    content += TextParsing::g_CEnd;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateWarnLog(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_WarnLog;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateRepeatKey(int addIndentationCount, StringView repeatKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_LogSystemTextBegin;
    content += lowerClassName;
    content += repeatKey;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLogAssert(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_LogAssert;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateEraseIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += lowerClassName;
    content += TextParsing::g_EraseIter;
    content += lowerClassName;
    content += TextParsing::g_End;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GetLowerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lowerClassName;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateInit() const
{
    auto content = GenerateLoop();

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateCSVRowInit();
    content += GenerateEmplaceBack();

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::g_NewlineCharacter;

    return content;
}