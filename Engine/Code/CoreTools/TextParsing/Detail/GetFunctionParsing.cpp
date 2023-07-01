///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "GetFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::GetFunctionParsing::GetFunctionParsing(CSVHead csvHead, String keyTypeDescribe) noexcept
    : ParentType{ 2 }, keyTypeDescribe{ std::move(keyTypeDescribe) }, head{ std::move(csvHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GetFunctionParsing)

System::String CoreTools::GetFunctionParsing::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyTypeDescribe;
}

CoreTools::CSVHead CoreTools::GetFunctionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head;
}

int CoreTools::GetFunctionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.GetCount();
}

System::String CoreTools::GetFunctionParsing::GenerateGetKeyFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateKeyFunctionStatement();

    content += GenerateFunctionBeginBrackets();
    content += GenerateReturnKey();
    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateKeyFunctionStatement() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscard;
    content += TextParsing::gConstexprStatic;
    content += GetKeyTypeDescribe();
    content += TextParsing::gGenerateKey;

    content += GenerateKeyParameter();
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateReturnKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += csvHead.GetKey();
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateKeyParameter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::gSpace;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::gComma;
            content += TextParsing::gSpace;
        }
    }

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateCountFunction(const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateGetValueFunction(const String& valueType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    if (valueType == SYSTEM_TEXT("System::String"))
    {
        content += SYSTEM_TEXT("String");
    }
    else
    {
        content += valueType;
    }

    content += TextParsing::gSpace;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateBeginIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += actualType;
    content += SYSTEM_TEXT("ConstIter");
    content += TextParsing::gSpace;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateEndIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += actualType;
    content += SYSTEM_TEXT("ConstIter");
    content += TextParsing::gSpace;
    content += functionVariableName;
    content += endDescribe;

    return content;
}
