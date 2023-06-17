///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:59)

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
    switch (const auto csvFormatType = csvHead.GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::Vector:
        {
            return std::make_shared<VectorContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
        case CSVFormatType::Unique:
        {
            return std::make_shared<UniqueContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }

        default:
        {
            return std::make_shared<DefaultContainerDefaultFunctionDefinitionParsing>(csvHead, className);
        }
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

    auto content = GenerateConstructor(TextParsing::gCSVContent);

    content += GenerateContainerMember();

    content += GenerateFunctionBeginBrackets();

    content += GenerateContainerParsing();
    content += GenerateUserSelfClassIsValid9(1);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

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

    content += TextParsing::gNewlineCharacter;
    content += GenerateIndentation(1);
    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表结束载入……\"));\n");

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gColon;
    content += TextParsing::gSpace;
    content += lowerClassName;
    content += TextParsing::gInit;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerParsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gParsingContent;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerParsingFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    String content{ TextParsing::gVoid };

    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += TextParsing::gParsing;
    content += TextParsing::gCSVContent;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateContainerSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表开始载入……\"));\n\n");

    content += GenerateIndentation(1);
    content += TextParsing::gContentSize;
    content += GenerateIndentation(1);
    content += SYSTEM_TEXT("const auto csvHead = csvContent.GetCSVHead();\n\n");

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLoop() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gLoop;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateCSVRowInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gCSVRowInit;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateEmplaceBack() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    const auto csvHead = GetCSVHead();

    content += lowerClassName;
    content += TextParsing::gEmplaceBack;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gCSVRowCall;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateSort() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gSort;
    content += lowerClassName;
    content += TextParsing::gFunction;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateReturnKeyLess() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gReturnKeyLess;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateReturnKeyEqual() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gKeyEqual;
    content += GenerateIndentation(2);
    content += TextParsing::gLeftBrace;
    content += TextParsing::gNewlineCharacter;
    content += GenerateIndentation(3);
    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表存在重复主键，key = \"), (*lhs).GetKey(), SYSTEM_TEXT(\"。\\n\"), CoreTools::LogAppenderIOManageSign::TriggerAssert);\n\n");
    content += GenerateIndentation(3);
    content += TextParsing::gReturnTrue;
    content += GenerateIndentation(2);
    content += TextParsing::gRightBrace;
    content += TextParsing::gNewlineCharacter;
    content += GenerateIndentation(2);
    content += TextParsing::gElse;
    content += TextParsing::gNewlineCharacter;
    content += GenerateIndentation(2);
    content += TextParsing::gLeftBrace;
    content += TextParsing::gNewlineCharacter;
    content += GenerateIndentation(3);
    content += TextParsing::gReturnFalse;
    content += GenerateIndentation(2);
    content += TextParsing::gRightBrace;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLambdaEnd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gLambdaEnd;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateUnique() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gUnique;
    content += lowerClassName;
    content += TextParsing::gFunction;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateIfIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIfIterBegin;
    content += TextParsing::gIterEnd;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateWarnLog(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gWarnLog;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateRepeatKey(int addIndentationCount, StringView repeatKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gSpace;
    content += TextParsing::gSystemText;
    content += lowerClassName;
    content += repeatKey;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateLogAssert(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gLogAssert;

    return content;
}

System::String CoreTools::ContainerDefaultFunctionDefinitionParsing::GenerateEraseIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += lowerClassName;
    content += TextParsing::gEraseIterBegin;
    content += TextParsing::gSmallIter;
    content += TextParsing::gDot;
    content += TextParsing::gEnd;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

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
    content += TextParsing::gNewlineCharacter;

    return content;
}